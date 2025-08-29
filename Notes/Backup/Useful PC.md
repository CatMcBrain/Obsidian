
## My apps

- Obsidian
- VSCode
- TickTick
- Mechvibes
- Pasteintofile
- PDFXchange
- WhatsApp
- Pcloud
- REAPER
- Firefox
- qbittorrent
- git
- y2-dlp (FFMPEG)
- discord
- autohotkey
- antimicro
- TegraRCM
- Spacedesk
- 7zip
- hidhide
- python
- scrcpy
- ASIO4ALL
- Drive
- Microsoft365
- Miktex
- NS USBLoader
- Steam
- Xournal++
- reWASD
- Teracopy
_____________________
- (calibre)
- (globalprotect)
- (mpv)
- (iriun webcam)
- (musicbee)
- (OBS)
- ([QuickShare](https://www.geeksforgeeks.org/restore-win-missing-background-apps/))

## Windows 11 old context menu
**Restore the old Context Menu in Windows 11**

  

1. Right-click the Start button and choose **Windows Terminal.**
    
2. Copy the command from below, paste it into Windows Terminal Window, and press enter.
    
    1. _reg.exe add "HKCU\Software\Classes\CLSID\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}\InprocServer32" /f /ve_
        
3. **Restart File Explorer** or your computer for the changes to take effect.
    
4. You would see the Legacy Right Click Context menu by **default**.


**Restore Modern Context menus in Windows 11**

  

To undo this change, in a Terminal Window, execute this command:

_reg.exe delete "HKCU\Software\Classes\CLSID\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}" /f_

**Restart** the File Explorer or Computer for the changes to take effect.

## Revert to a Github commit

![[Pasted image 20250703161230.png]]