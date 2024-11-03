## CONAN2 COMMAND CHEET SHEET

### Setup Commands
'requirement.txt'in hazır olduğunu ve sistemde python kurulu olduğunu varsayalım.
```
$ python -m venv conanenv
$ conanenv\Scripts\activate
$ pip install -r requirements.txt
```

### Profile Commands
```
$ conan profile detect --force
# İşletim sistemini, varsayılan derleyiciyi tespit eder varsayılan olarak Release seçer ve varsayılan bir profil yaratır.

$ conan profile path <profile_name>
# Verilen profilin hangi dizinde bulunduğunu yazdırır.

$ conan create . --profile=<profile_name>
#
```

### Build Commands

#### Yol 1
```
# 'recipe'de(conanfile.py) tarif edilen ayarlara göre gereklilikleri yükler. 
# '--output-folder=build' ile üretilen 'build' dosyalarının konulacağı klasör 'build' olarak belirlenir.
# '--build=missing' ile 'binary' dosyaları bulunmayan paketlerin kaynak dosyalarından derlenerek kullanılacağını belirler.
# '--settings=build_type=Release' profil içerisinde de belirtilen 'build_type' değerini ayarlar. Burada 'Release' ve 'Debug' için ayrı profil dosyaları yerine bu parametre kullanılabilir.
# '--profile=<profile_name>' seçili profil kullanılır.
$ conan install . --output-folder=build --build=missing --settings=build_type=Release --profile=<profile_name>

# 'conan install' sonrasında cmake'in komutlarıyla derleme işlemi gerçekleştirilir.
# Kullanılan 'generator' multi-config değilse cmake 'configuration' aşamsında CMAKE_BUILD_TYPE verilmelidir.
$ cd build
$ cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
```

#### Yol 2
```
# 'recipe' içerisinde 'layout' metodu 'cmake_layout(self)' şeklinde tanımlanırsa 'conan install' şu şekilde kullanılabilir.
$ conan install . --build=missing --settings=build_type=Release --profile=<profile_name>

# 'conan install' komutu CMakeUserPresets.json ve CMakePresets.json dosyalarını üretebilmektedir.
# CMake minimum 3.19 versiyonu için 'preset' dosyaları kullanılarak 'configure' ve 'build' işlemleri yapılabilir.
$ cmake --preset=conan-release
$ cmake --build --preset=conan-release
```


### Common Commands
```
# 'Local'de yüklenen paketlerin ve profillerin tutulduğu dizini gösterir.
$ conan config home

# Yeni bir "Hello World" C++ projesi yaratır.
$ conan new cmake_lib -d name=hello -d version=1.0
```


$ cmake --preset conan-debug
$ cmake --build --preset conan-debug
$ conan config home
$ conan install . --output-folder=build --build=missing --settings=build_type=Debug
$ conan install . --output-folder=build --build=missing --options=zlib/1.2.11:shared=True
$ conan create . 	-> Can take same parameters with conan install
$ conan list "hello/1.0:*"
$ conan export-pkg . --profile=<profile_name>