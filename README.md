## Pet Water Dispenser

Projek ini bertujuan untuk membuat alat pengisi wadah minum hewan peliharaan secara otomatis. Alat ini dapat berguna bagi para pemilik hewan peliharaan (anjing, kucing, dll.) yang ingin memastikan bahwa peliharaan mereka selalu mempunyai akses air. Alat ini terdiri atas 2 buah komponen utama yaitu tank air dan mangkok kecil. Sensor yang digunakan disini yaitu sensor ultrasonic dan sensor water-level.

Alat dan bahan:
- Sensor Water Level
- Sensor Ultrasonic
- Pompa air mini https://www.tokopedia.com/alfaelectro/mini-submersible-water-pump-pompa-air-celup-3v-5v-dc-bisa-utk-arduino-horizontal
- Tank (Botol Aqua 1,5L dipotong atasnya)
- Mangkok kecil https://www.tokopedia.com/petshopmakassarsafari/piring-kotak-tempat-makan-minum-mangkok-mangkuk-kucing-anjing-kelinci
- Arduino
- I2C LCD
- Kabel jumper

Cara kerja:
1. Sensor ultrasonik yang dipasangkan diatas tank akan mengukur apakah air pada tank masih cukup atau hampir habis dengan menentukan ketinggiannya.
2. Apabila tank hampir/sudah habis, pesan warning akan ditampilkan pada I2C LCD agar pemilik segera mengisi ulang tank-nya.
3. Pada mangkok kecil, dipasangkan sensor water-level yang akan memantau ketinggian level air.
4. Apabila ketinggian air pada mangkok kurang dari batas tertentu dan tank air masih cukup, Arduino akan menyalakan pompa air sehingga mangkok kecil dapat terisi dengan air.
5. Hewan peliharaan dapat meminum air pada mangkok.
