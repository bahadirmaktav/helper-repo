İçindekiler :
	1. VSCode-win32-x64-1.93.1 :
		VScode uygulamasının 1.93.1 versiyonunu içerir. 'Portable Mode' olacak şekilde ayarlanmıştır. Protable olması nedeniyle kullanıcı ayarları ve 'extension'lar 'data' klasörü içerisinde yer alır. Böylece başka bir sistemde aynı geliştirme ortamı kullanılmak istendiğinde sadece klasörün taşınması yeterlidir.

	2. VSCodeExtensions
		Yazılım geliştirme sürecinde (Özellikle C++ dilinin kulanıldığı süreçlerde) faydalı olabilecek VSCode 'extension'larını içermektedir.
		'Extension' listesi:
			. C/C++                            - 1.21.6     - Microsoft
			. C/C++ Advance Lint               - 1.15.0     - Joseph Benden
			. C/C++ Themes                     - 2.0.0      - Microsoft
			. CMake                            - 0.0.17     - twxs
			. CMake Tools                      - 1.19.51    - Microsoft
			. Doxygen Documentation Generator  - 1.4.0      - Christoph Schlosser
			. Git Graph                        - 1.30.0     - mhutchie
			. Hex Editor                       - 1.10.0     - Microsoft
			. Material Icon Theme              - 5.11.1     - Philipp Kief
			. PlantUML                         - 2.18.1     - jebbs
			. Todo Tree                        - 0.0.226    - Gruntfuggly
			. Conventional Commits             - 1.26.0     - vivaxy

	3. settings.json
		Örnek bir 'User Setting JSON' (VSCode kullanıcı ayarlarını içeren dosyadır.) dosyasıdır.
		Dosyanın içerisindekileri VSCode'da yer alan 'User Settings JSON'a ekleyerek kullanılabilir.
		Proje içerisinde '.vscode' klasörü altına eklenerek de kullanılabilir.

	4. c_cpp_properties.json
		C/C++ extension'ı ile ilgili ayarları içeren dosyadır. Proje içerisinde '.vscode' klasörü altına eklenerek kullanılabilir.

	5. .clang-format
		'settings.json' içerisinde, 'C/C++ extension'ı format özelliği için '.clang-format' dosyası kullanılacak şekilde ayarlanmıştır. '.clang-format' içerisinde Google Format style referans alınarak geliştirmiş bir clang-format dosyası hazırlanmıştır. VSCode üzerinden 'format document' çalıştırıldığında, dosyada belirtilen ayarlara göre format işlemi gerçekleştirilir.