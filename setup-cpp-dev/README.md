İçindekiler :
	1. VSCode Extensions
		Ayarlar aşağıdaki extension listesinde yer alan araçlar için gerçekleştirilmiştir.
		Extension listesi:
			. C/C++                               - Microsoft
			. C/C++ Themes                        - Microsoft
			. CMake Tools                         - Microsoft
			. Doxygen Documentation Generator     - Christoph Schlosser
			. Hex Editor                          - Microsoft
			. PlantUML                            - jebbs
			. Todo Tree                           - Gruntfuggly
			. Conventional Commits                - vivaxy
			. SonarQube for IDE                   - SOnarSource

	3. settings.json
		Örnek bir 'User Setting JSON' (VSCode kullanıcı ayarlarını içeren dosyadır.) dosyasıdır.
		Dosyanın içerisindekileri VSCode'da yer alan 'User Settings JSON'a ekleyerek kullanılabilir.
		Proje içerisinde '.vscode' klasörü altına eklenerek de kullanılabilir.

	4. c_cpp_properties.json
		C/C++ extension'ı ile ilgili ayarları içeren dosyadır. Proje içerisinde '.vscode' klasörü altına eklenerek kullanılabilir.

	5. .clang-format
		'settings.json' içerisinde, 'C/C++ extension'ı format özelliği için '.clang-format' dosyası kullanılacak şekilde ayarlanmıştır. 
		'.clang-format' içerisinde Google Format style referans alınarak geliştirmiş bir clang-format dosyası hazırlanmıştır. 
		VSCode üzerinden 'format document' çalıştırıldığında, dosyada belirtilen ayarlara göre format işlemi gerçekleştirilir.