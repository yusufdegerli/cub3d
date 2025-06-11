Cub3D
Proje Hakkında
Cub3D, 42 Network müfredatında yer alan ileri düzey bir C programlama projesidir. Bu proje, 1990'ların klasik oyunu Wolfenstein 3D'den ilham alarak, raycasting tekniği kullanılarak 2D bir haritadan 3D benzeri bir görüntü oluşturan bir oyun motoru geliştirmeyi amaçlar. Proje, grafik programlama, matematiksel hesaplamalar, dosya ayrıştırma ve performans optimizasyonu gibi becerileri öğretmek için tasarlanmıştır. Kendi Cub3D programımı geliştirirken, MiniLibX kütüphanesi ile grafik render etme, raycasting algoritmaları, dosya işleme ve kullanıcı girdilerini yönetme konularında derinlemesine deneyim kazandım.
Bu proje, hem görsel olarak etkileyici bir 3D ortam sunar hem de karmaşık matematiksel hesaplamalar ve sistem programlama becerilerini bir araya getirir. Bonus özellikleri implemente ederek ek işlevsellikler ekledim.
Özellikler
Cub3D, aşağıdaki işlevselliği sağlar:
Zorunlu Kısım

Oyun Mekanikleri:
Oyuncu, bir 2D haritada birinci şahıs bakış açısıyla (FPS) hareket eder.
Hareket: WASD tuşlarıyla ileri/geri ve yana hareket, ok tuşlarıyla (veya fareyle) dönme.
Harita, duvarlar (1), boş alanlar (0) ve oyuncu başlangıç pozisyonu (N, S, E, W) içerir.


Raycasting:
2D haritadan 3D benzeri bir görüntü oluşturmak için raycasting algoritması kullanıldı.
Her piksel sütunu için bir ışın (ray) gönderilir, duvar mesafeleri hesaplanır ve perspektif düzeltilmiş 3D görüntü render edilir.


Harita Ayrıştırma:
Harita, .cub uzantılı bir dosyadan okunur.
Harita geçerlilik kontrolleri: Kapalı duvarlar, geçerli karakterler, tek oyuncu pozisyonu.
Renk tanımlamaları: Zemin (F) ve tavan (C) için RGB renkleri.
Doku tanımlamaları: Kuzey (NO), Güney (SO), Batı (WE), Doğu (EA) için doku dosyaları.


Grafik Özellikleri:
MiniLibX kullanılarak pencere yönetimi, görüntü render etme ve sprite çizimi.
Duvarlar için doku (texture) desteği.
Zemin ve tavan için düz renkler.


Kullanıcı Girdileri:
Klavye: WASD (hareket), ok tuşları (dönme), Esc (çıkış).
Pencere kapatma ile oyun sonlanır.


Hata Yönetimi:
Geçersiz harita formatları (açık duvarlar, eksik oyuncu, geçersiz karakterler).
Doku dosyası hataları (erişilemeyen veya yanlış formatlı dosyalar).
Geçersiz RGB değerleri veya eksik yapılandırmalar.



Bonus Kısım (Opsiyonel)

Ek Hareketler:
Fare ile kamera kontrolü.
Çömelme veya zıplama gibi ek hareket mekanikleri.


Gelişmiş Grafikler:
Minimapa: Haritanın 2D görünümünü gösteren bir overlay.
Sprite’lar: Haritada toplanabilir nesneler veya düşmanlar.
Duvar çarpışmaları: Oyuncunun duvarlara çarpmasını engelleme.


Ek Özellikler:
Kapılar: Açılıp kapanabilen dinamik harita elemanları.
Animasyonlu dokular veya gökyüzü kutusu (skybox).
Ses efektleri veya arka plan müziği (MiniLibX’in ses desteği sınırlı olduğundan harici kütüphanelerle).


Performans Optimizasyonları:
Raycasting döngüsünde vektör hesaplamaları optimize edildi.
Gereksiz render işlemlerini azaltmak için önbellekleme.



Teknik Detaylar

Veri Yapıları:
Harita: 2D bir dizi (array) veya bağlantılı liste olarak saklanır.
Oyuncu: Struct ile pozisyon (x, y), yön vektörü ve görüş açısı (FOV) tutulur.
Doku: Her yön için doku verileri (MiniLibX image pointer’ları).
Ray: Her ışın için mesafe, çarpma noktası ve doku bilgisi tutulur.


Raycasting Algoritması:
DDA (Digital Differential Analyzer): Harita karelerinde ışın-duvar kesişimlerini hesaplar.
Perspektif düzeltme: Duvar yükseklikleri mesafeye bağlı olarak ölçeklenir.
Doku eşleme: Çarpma noktasına göre doğru doku pikseli seçilir.


Ayrıştırma (Parsing):
Harita dosyası satır satır okunur, yapılandırma (NO, SO, WE, EA, F, C) ve harita verileri ayrıştırılır.
Geçerlilik kontrolleri: Kapalı duvarlar, tek oyuncu, geçerli karakterler.


Grafik Render:
MiniLibX ile her kare (frame) için ekran yeniden çizilir.
Duvarlar, zemin ve tavan ayrı ayrı render edilir.
Doku eşleme için piksel manipülasyonu kullanılır.


Performans Optimizasyonları:
Sabit matematiksel hesaplamalar (örneğin, trigonometrik fonksiyonlar) önbelleklendi.
Gereksiz MiniLibX çağrıları azaltıldı.
Büyük haritalar için verimli bellek yönetimi.
Çoklu iş parçacığı (opsiyonel, bonus için): Raycasting paralel hale getirildi.


Hata Önleme:
Bellek sızıntıları için Valgrind ile test edildi.
Edge case’ler: Küçük haritalar, büyük haritalar, eksik dokular, geçersiz RGB.



Kurulum ve Kullanım
Gereksinimler

C derleyicisi (gcc veya clang önerilir).
MiniLibX kütüphanesi (Linux veya macOS için uygun sürüm).
POSIX uyumlu bir işletim sistemi (Linux veya macOS).
make komutu (Makefile ile derleme için).

Kurulum

Repoyu klonlayın:git clone https://github.com/yusufdegerli/cub3d.git
cd cub3d


MiniLibX kütüphanesini kurun:
Linux:sudo apt-get install libx11-dev libxext-dev

MiniLibX kütüphanesini projenizin dizinine ekleyin veya sisteminize kurun.
macOS:MiniLibX’in macOS sürümünü kullanın (genellikle proje dizininde sağlanır).


Projeyi derleyin:make

Bu komut, cub3d çalıştırılabilir dosyasını oluşturur.
Bonus kısmı için:make bonus

Bu, cub3d_bonus çalıştırılabilir dosyasını oluşturur.

Kullanım

Zorunlu kısmı çalıştırın:./cub3d maps/valid_map.cub


maps/valid_map.cub, geçerli bir harita dosyası olmalıdır.2ევ


Bonus kısmı çalıştırın:./cub3d_bonus maps/valid_map.cub


Oyun kontrolleri:
WASD: Hareket (ileri, geri, sola, sağa).
Ok Tuşları: Kamera dönüşü (sol, sağ).
Esc: Oyunu sonlandır.
Fare (bonus): Kamera kontrolü.
Boşluk (bonus, opsiyonel): Kapı açma/kapama veya özel aksiyonlar.



Örnek Harita Dosyası
Bir .cub dosyası örneği:
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

1111111111
1000000001
10N0000001
1000000001
1111111111


Haritayı maps/example.cub olarak kaydedin ve çalıştırın:./cub3d maps/example.cub



Makefile Komutları

make: cub3d programını derler.
make clean: Ara dosyaları siler.
make fclean: Ara dosyaları ve çalıştırılabilir dosyaları siler.
make re: Her şeyi siler ve yeniden derler.
make bonus: cub3d_bonus programını derler.

Test Etme
Projenizi test etmek için aşağıdaki yöntemleri kullanabilirsiniz:

Manuel Test:
Farklı harita boyutları ve düzenleri (küçük, büyük, geçersiz haritalar).
Hata durumları: Eksik dokular, geçersiz RGB, açık duvarlar.
Kontroller: WASD, ok tuşları, fare (bonus), Esc.
Bonus özellikler: Minimapa, sprite’lar, kapılar, animasyonlar.


Otomatik Test Araçları:
cclaude42/cub3d_tester: Harita doğrulama ve render testi.
Kendi test haritalarınızı oluşturun (örneğin, karmaşık haritalar, kenar durumları).


Valgrind ile Bellek Testi:valgrind --leak-check=full ./cub3d maps/valid_map.cub



Kod Yapısı
Proje, modüler bir yaklaşımla yazılmıştır:

main.c: Programın giriş noktası, başlatma ve oyun döngüsü.
parser.c: Harita dosyasını ayrıştırma ve doğrulama.
raycasting.c: Raycasting algoritması ve render mantığı.
graphics.c: MiniLibX ile görüntü render etme ve doku yönetimi.
input.c: Klavye ve fare girdilerini işleme.
utils.c: Yardımcı fonksiyonlar (matematiksel hesaplamalar, hata yönetimi).
cub3d.h: Fonksiyon prototipleri, yapılar ve tanımlar.
libft/: Libft kütüphanesi (string ve diğer işlemler için).

Örnek Kullanım

Örnek harita ile başlatın:./cub3d maps/valid_map.cub


Oyunu oynayın:
WASD ile hareket edin, ok tuşlarıyla etrafa bakın.
Bonus özellikler: Fare ile dönüş, minimapa, kapılar.



Öğrenilenler
Bu proje sayesinde aşağıdaki becerileri geliştirdim:

Grafik Programlama: MiniLibX ile 3D benzeri render, doku eşleme.
Raycasting: DDA algoritması, perspektif düzeltme, mesafe hesaplamaları.
Matematik: Vektör işlemleri, trigonometrik hesaplamalar.
Dosya Ayrıştırma: Karmaşık dosya formatlarını işleme, hata kontrolü.
Hafıza Yönetimi: Dinamik bellek tahsisi ve sızıntı önleme.
Modüler Kod: Okunabilir, yeniden kullanılabilir ve bakımı kolay kod yazımı.
Performans Optimizasyonu: Hızlı render, önbellekleme, verimli döngüler.

Katkıda Bulunma
Eğer bu projeye katkıda bulunmak isterseniz:

Repoyu fork edin.
Yeni bir dal (branch) oluşturun: git checkout -b feature/yeni-ozellik.
Değişikliklerinizi yapın ve commit edin: git commit -m "Yeni özellik eklendi".
Dalınızı push edin: git push origin feature/yeni-ozellik.
Bir Pull Request açın.

Lisans
Bu proje, MIT Lisansı altında lisanslanmıştır.
Not: Bu README, 42 Network'ün Cub3D projesi için hazırlanmıştır. Projenizi 42 kurallarına uygun şekilde teslim ediyorsanız, lütfen 42'nin GitHub paylaşım politikalarını kontrol edin.
