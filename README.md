# UploadAndOpenURL

This small utility used for own share screenshots servise.

# How to use

1. You need to download and install Greenshot (getgreenshot.org/) program.
2. Download and install WinSCP (https://winscp.net).
3. Copy this utility to WinSCP folder.
4. Create config file for WinSCP. This dhould be lick that:
```
option batch abort
option confirm off
open ftp://LOGIN:PASSWORD@ftp.unick-soft.ru
# Change remote directory (change this to the desired directory on your server)
# cd FOLDER ON SERVER
# Upload the file to current working directory
put %1% 
close
exit
```
5 Add external tool to Greenshot. Use this settings:
 * Name: Upload to ftp
 * Command: C:\Users\Hacker\upload\UploadAndOpenURL.exe
 * Aguments: SCRIPT_NAME ""{0}"" FOLDER_ON_WEB_SITE
 * Exampel of arguments: C:\Users\upload\upload.txt ""{0}"" http://unick-soft.ru/photos/share/

You can choose Upload to ftp command, when you will do screenshots using Greenshot.
