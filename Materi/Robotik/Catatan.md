# Robotik

**24/07/2020**
- Pembelajaran yang berhubungan:
  - Science
  - Math
  - Engineering
  - Teknologi: Menciptakan hal baru untuk perkembangan jaman, atau yang sesuai dengan era sekarang.
- Komponen Utama Robot:
  - Controller (Otak): Berfungsi untuk menjalankan program, menerima dan mengolah setiap informasi dari input sensor, dan juga yang mengirim dan mengendalikan output pada actuator, indikator, atau juga audio. (Arduino)
  - Actuator (Otot): Untuk menggerakan robot. (DC Motor)
  - Sensor (Indera): Sebagai Indera robot. (Sensor suara, cahaya, dll.)
  - Battery (Sumber Energi): Merupakan sumber energi bagi robot.
  - Kabel (Urat): Menghantarkan data Input dan Output.
  - Frame (Tulang): Sebagai tulang yang menyangga antara servo pada robot. Juga yang membentuk robot menjadi berbagai macam, dan penunjang penampilan robot.
  - Chasis (Rangka): Rangka utama pada robot, biasanya menjadi badan bagi si robot.
  - Support: Komponen pendukung terbentuknya robot, seperti baud dan mur.

**14/08/2020**
- Program yang digunakan: Arduino IDE
- Tombol check pada kiri atas adalah tombol compiler
- Tombol uploader untuk mengunggah program ke board
- Void Setup: Untuk kode yang dieksekusi sekali. Digunakan untuk setup.
  - Yang dapat disetup: 
    - Mensetting komponen menjadi INPUT atau OUTPUT
- Void Loop: Untuk kode yang dieksekusi berulang-ulang sampai program dimatikan.

- ARDUINO LANGUAGE FUNCTIONS:
  - digitalWrite(componenets, {HIGH/LOW}) // High = 5V, Low < 5

**28/08/2020**
- Ilmu Math -> Rumus yang kita gunakan
- Contohnya: Sensor ultrasonik

- **ARDUINO**
- Pin Digital: 0-13
- Pin Analog: A0-A5
- Pin Hambatan: GND/Ground
- Pin Tegangan: Pin 3.3V dan 5V

- **SENSOR API**
- Potensiometer pada sensor Api adalah yang warna Biru
- Pin D0 dihubungkan ke pin digital
- Pin A0 dihubungkan ke pin Analog, menghasilkan nilai kisaran 0-1024