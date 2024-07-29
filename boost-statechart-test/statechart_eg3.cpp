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

struct EvBwC : sc::event<EvBwC> {};
struct EvCwD : sc::event<EvCwD> {};

struct A;
struct ExampleStateMachine : sc::state_machine<ExampleStateMachine, A> {};

struct B;
struct A : sc::simple_state<A, ExampleStateMachine, B> {
  A() { std::cout << "A Entry Action called!" << std::endl; }
  ~A() { std::cout << "A Exit Action called!" << std::endl; }
};
struct C;
struct B : sc::simple_state<B, A> {
  typedef sc::custom_reaction<EvBwC> reactions;
  B() { std::cout << "B Entry Action called!" << std::endl; }
  ~B() { 
    std::cout << "B Exit Action called!" << std::endl;
    post_event(EvCwD());
  }
  sc::result react(const EvBwC&) {
    std::cout << "B -> C Transition Action called!" << std::endl;
    return transit<C>();
  }
};
struct D;
struct C : sc::simple_state<C, A> {
  typedef mpl::list<sc::transition<EvCwD, D>> reactions;
  C() { std::cout << "C Entry Action called!" << std::endl; }
  ~C() { std::cout << "C Exit Action called!" << std::endl; }
};
struct D : sc::state<D, A> {
  D(my_context ctx) : my_base(ctx) { std::cout << "D Entry Action called!" << std::endl; }
  ~D() { std::cout << "D Exit called!" << std::endl; }
};

int main() {
  ExampleStateMachine sm;
  std::cout << "\n--------- initiate -----------\n";
  sm.initiate();

  std::cout << "\n---------- EvBwC ----------\n";
  sm.process_event(EvBwC());
}