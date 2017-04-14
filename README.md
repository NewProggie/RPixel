# RPixel
Some code and deploy scripts for my Raspberry Pi 2 with an attached 2.8'' 320x240 TFT Panel from Adafruit

## Raspbian Jessie Lite 2016/09-based image
https://s3.amazonaws.com/adafruit-raspberry-pi/2016-10-18-pitft-28r-lite.zip

### Deploy image onto Raspberry pi (using OSX)
    $ diskutil list
    $ diskutil unmountDisk /dev/disk<disk# from diskutil>
    $ sudo dd bs=1m if=image.img of=/dev/rdisk<disk# from diskutil>
    $ sudo diskutil eject /dev/rdisk<disk# from diskutil>
    
## Setup Raspberry Pi
    $ sudo raspi-config

### Enable WLAN (using the famous Edimax dongle): 
https://www.randombrick.de/raspberry-pi-2-edimax-wlan-einrichten/

### Install new kernel (provided by Adafruit)
    $ curl -SLs https://apt.adafruit.com/add-pin | sudo bash
    $ sudo apt-get install raspberrypi-bootloader adafruit-pitft-helper raspberrypi-kernel

### Enable and configure the TFT panel
    $ sudo adafruit-pitft-helper -t 28r
    
### Bootstrap development environment
    $ sudo apt-get install vim-nox git cmake tmux clang-format-3.9 clang-tidy-3.9 libcairo2-dev
    $ git clone https://github.com/NewProggie/Dev-Utils.git
    $ cd Dev-Utils && bash init_dotfiles.sh
