# Singing Christmas Card 🎅

A singing Christmas card made using an Arduino Pro Mini, piezoelectric buzzer, LEDS, an optical reflective sensor, and some Christmas spirit!

## Santa's playlist:
- We wish you a merry Christmas
- Jingle Bells
- Rudolph the rednose reindeer

<img width="1088" alt="image" src="https://github.com/Blargian/singing-card/assets/41984034/9e56be38-fdf2-45ff-a76a-9e587f2c1e54">

### Design analysis and future improvements 

An Arduino pro mini is not the ideal choice of MCU for this project, but it was what I had lying around - as a proof of concept it's okay. In future I would probably scrap the Arduino for something like an Atmel ATTiny13, with some EPROM for storing the songs or some other some small low power pin count MCU. It might also be fun to explore miniaturizing the electronics even more, perhaps design an ultra small PCB with surface mount piezo, sensor, resistors and battery.

I don't enjoy using the Arduino IDE so I explored using CMake in this project. Still some issues here though, I had trouble integrating GoogleTest for unit tests because the target platform is ARM. Possible to get it working but not so easily. In future I'd scrap Arduino and write everything in C or assembly, that would allow more flexibility.  

### Disclaimer

No reindeer or elves were harmed in the making of this production.  
