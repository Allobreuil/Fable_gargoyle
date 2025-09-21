# 🗿 Fable Gargoyle

Interactive recreation of the **gargoyles from Fable II**.  
This project combines **electronics**, **embedded software (Arduino Nano ESP32)**, and **3D modeling** to bring a talking, reactive gargoyle to life.

---

## 📂 Project structure

- **3d_model/** → 3D models of the gargoyle (3D printing)  
- **hardware/** → electronic schematics and PCB (KiCad)  
- **software/** → source code for Arduino Nano ESP32  
- **sounds_fr/** → French audio files for the gargoyle voice  

---

## 🛠️ Required hardware

- [Arduino Nano ESP32](https://store.arduino.cc/products/nano-esp32)  
- [Speaker](https://www.amazon.fr/XYWHPGV-Haut-parleur-Diam%C3%A8tre-projet-%C3%A9lectronique/dp/B0CP25TYPF)  
- [DFPlayer Mini MP3 Player](https://www.amazon.fr/dp/B089D5NLW1?ref=ppx_yo2ov_dt_b_fed_asin_title)  
- [Switch](https://www.amazon.fr/Interrupteur-Commutateur-Conviennent-%C3%89lectroniques-dInterrupteur/dp/B086QGZRKG)  
- [9V Battery](https://www.amazon.fr/Duracell-Piles-9V-Plus-paquet/dp/B093LQHR2Y)  
- [5V Regulator L7805CV](https://www.amazon.fr/STMICROELECTRONICS-r%C3%A9gulateurs-tension-positive-L7805CV/dp/B007DQ4FXC)  
- [9V Battery power cable](https://www.amazon.fr/dp/B076NQXMP2?ref=ppx_yo2ov_dt_b_fed_asin_title)  
- [SD card](https://www.amazon.fr/dp/B08GY9NYRM?ref=ppx_yo2ov_dt_b_fed_asin_title)  
- [HC-SR501 Motion Sensor](https://www.amazon.fr/dp/B071FBG4XW?ref=ppx_yo2ov_dt_b_fed_asin_title)  

## ⚡ Installation

### 1. Electronics
- Open the `hardware/` folder in **KiCad** to check the schematic and PCB.  
- Assemble and solder the listed components.  
- Connect the speaker and the motion sensor according to the schematic.  

### 2. Software
1. Install the Arduino IDE and ESP32 drivers.  
2. Add ESP32 board support in the Arduino IDE.  
3. Open the `software/` folder.  
4. Flash the code named **`Gargoyle_V2`** to the Arduino Nano ESP32.  

### 3. 3D Model
- The files in the `3d_model/` folder can be used to 3D print the gargoyle.  
- The folder also includes a **split version of the gargoyle**, divided into several parts to make large-scale printing easier.  
- You can adjust the model to your needs (size, material, color).  

---

## 📖 User Manual

1. **Prepare the SD card**  
   - Copy all the `.mp3` files from the `sounds_fr/` folder.  
   - Paste them onto a FAT32-formatted SD card.  
   - Insert the SD card into the MP3 module.  

2. **Flash the Arduino**  
   - Open `Gargoyle_V2` in the `software/` folder with the Arduino IDE.  
   - Select the **Arduino Nano ESP32** board in the IDE.  
   - Flash the program to the microcontroller.  

3. **Assemble the system**  
   - Solder the components according to the KiCad schematic (`hardware/`).  
   - Insert the Arduino into the circuit.  
   - Connect the speaker, motion sensor, switch, and regulator.  
   - Power the system with a 9V battery.  

4. **Usage**  
   - Once powered on, the system is ready.  
   - When the **HC-SR501 motion sensor** detects movement in front of the gargoyle,  
     the Arduino plays a **random sound** from the SD card through the speaker.  

---

## 🤝 Contribution

Contributions are welcome:  
- Adding new voices or translations  
- Improving the ESP32 code (optimizations, new sensors, etc.)  
- Enhancing the 3D model (mechanical or aesthetic improvements)  

---

## 📜 License

- The **source code** (`software/` folder) is released under the **MIT License**.  
- The **hardware schematics** (`hardware/` folder) are also shared under the **MIT License**.  

⚠️ **Important**:  
- The **3D model** and **audio files** are **fan-made recreations** inspired by *Fable II*.  
- These elements are **copyrighted by their respective owners (Microsoft)**.  
- They are provided here **for educational and non-commercial purposes only**.  
- No copyright infringement is intended.  

---

## ⚖️ Legal Notice

This is a **fan project** inspired by *Fable II*.  
- The gargoyle model and sounds remain the intellectual property of Microsoft.  
- This repository is shared **for personal, educational, and non-commercial use only**.  
- Redistribution or commercial use of the copyrighted material is not permitted.  

---