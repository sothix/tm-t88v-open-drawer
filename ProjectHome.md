Open the Cash Drawer of Epson TM-T88V Reciept Printer and probably other models using the Advanced Printer Driver.  This program is a simple command line utility for opening the drawer written in c++ modified from EPSONS sample.


---


Download Epsons Advance printer driver 4 from here:
http://pos.epson.com/products/tm-t88v.htm

Install the driver to access the manuals and other sample programs.

Easily modifiable to use other commands referenced by EPSONS reference manual located:
C:\Program Files (x86)\EPSON\EPSON Advanced Printer Driver 4\Manual\US\APD4\_Status\_E\_RevS.pdf



---


Php file for popping the draw via HTML:

<?php
exec ("C:/wamp/www/pos/exec/OpenDrawer.exe",$output);
print\_r($output);
?>


---


Build Instructions
It is currently built using the code blocks free IDE: codeblocks-12.11mingw-setup.exe available at http://www.codeblocks.org/downloads and includes codeblocks project file.


---


WARNING:  Verified to not work with network printers


---


Standard Linux command to open drawer of the TM-T88V (does not require this software):

USB printer: echo -e -n "\x1b\x70\x30\x40\x50" > /dev/usb/lp0

Network CUPS Printer: echo -e -n "\x1b\x70\x30\x40\x50" | lpr -o raw -P Epson-TM-Network
