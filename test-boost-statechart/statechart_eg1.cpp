#include <iostream>

#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/state.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/custom_reaction.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/mpl/list.hpp>

namespace mpl = boost::mpl;
namespace sc = boost::statechart;

/************* Events *************/
struct EvAwA : sc::event<EvAwA> {};
struct EvBwC : sc::event<EvBwC> {};
struct EvCwD : sc::event<EvCwD> {
  EvCwD(int d) : data{d} {}
  int data;
};
struct EvDwA : sc::event<EvDwA> {};
struct EvEwF : sc::event<EvEwF> {};
struct EvGwH : sc::event<EvGwH> {};
/**********************************/

/**************** State Machine ****************/
struct A;
struct ExampleStateMachine : sc::state_machine<ExampleStateMachine, A> {};
/***********************************************/

/**************** States ****************/
struct B;
struct A : sc::simple_state<A, ExampleStateMachine, B> {
  typedef sc::transition<EvAwA, A> reactions;
  A() { std::cout << "A Entry Action called!" << std::endl; }
  ~A() { std::cout << "A Exit Action called!" << std::endl; }
};
struct C;
struct B : sc::simple_state<B, A> {
  typedef sc::custom_reaction<EvBwC> reactions;
  B() { std::cout << "B Entry Action called!" << std::endl; }
  ~B() { std::cout << "B Exit Action called!" << std::endl; }
  sc::result react(const EvBwC&) {
    std::cout << "B -> C Transition Action called!" << std::endl;
    return transit<C>();
  }
};
struct D;
struct C : sc::simple_state<C, A> {
  typedef mpl::list<
    sc::custom_reaction<EvCwD>,
    sc::transition<EvBwC, B>> reactions;
  C() { std::cout << "C Entry Action called!" << std::endl; }
  ~C() { std::cout << "C Exit Action called!" << std::endl; }
  sc::result react(const EvCwD& ev) {
    std::cout << "C -> D Transition Action called with transition data " << ev.data << "!" << std::endl;
    return transit<D>();
  }
};
struct E;
struct G;
struct D : sc::state<D, ExampleStateMachine, mpl::list<E, G>> {
  typedef sc::transition<EvDwA, A> reactions;
  D(my_context ctx) : my_base(ctx) { 
    const EvCwD* ev = dynamic_cast<const EvCwD*>(triggering_event());
    if(ev) {
      std::cout << "D Entry called with transition data << " << ev->data << "!" << std::endl;
    } else {
      std::cout << "ev is nullptr!" << std::endl;
    }
  }
  ~D() { std::cout << "D Exit called!" << std::endl; }
};
struct F;
struct E : sc::simple_state<E, D::orthogonal<0>> {
  typedef sc::transition<EvEwF, F> reactions;
  E() { std::cout << "E Entry called!" << std::endl; }
  ~E() { std::cout << "E Exit called!" << std::endl; }
};
struct F : sc::simple_state<F, D::orthogonal<0>> {
  typedef sc::transition<EvEwF, E> reactions;
  F() { std::cout << "F Entry called!" << std::endl; }
  ~F() { std::cout << "F Exit called!" << std::endl; }
};
struct H;
struct G : sc::simple_state<G, D::orthogonal<1>> {
  typedef sc::transition<EvGwH, H> reactions;
  G() { std::cout << "G Entry called!" << std::endl; }
  ~G() { std::cout << "G Exit called!" << std::endl; }
};
struct H : sc::simple_state<H, D::orthogonal<1>> {
  typedef sc::transition<EvGwH, G> reactions;
  H() { std::cout << "H Entry called!" << std::endl; }
  ~H() { std::cout << "H Exit called!" << std::endl; }
};
/****************************************/

int main() {
  ExampleStateMachine sm;
  std::cout << "\n--------- initiate -----------\n";
  sm.initiate();

  std::cout << "\n---------- EvBwC ----------\n";
  sm.process_event(EvBwC());

  std::cout << "\n---------- EvAwA ----------\n";
  sm.process_event(EvAwA());

  std::cout << "\n---------- EvCwD ----------\n";
  sm.process_event(EvCwD(42));

  std::cout << "\n---------- EvBwC ----------\n";
  sm.process_event(EvBwC());

  std::cout << "\n---------- EvCwD ----------\n";
  sm.process_event(EvCwD(42));

  std::cout << "\n---------- EvGwH ----------\n";
  sm.process_event(EvGwH());

  std::cout << "\n---------- EvEwF ----------\n";
  sm.process_event(EvEwF());

  std::cout << "\n---------- EvDwA ----------\n";
  sm.process_event(EvDwA());
}