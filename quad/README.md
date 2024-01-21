# quad
The goal of this repo is to provide some low level access to the semantics of DayZ log files.

Rule No 1: Nothing to install or Mods to download to your DayZ server  
Rule No 2: Doesn't require admin privileges to use  
Rule No 3: Simple, basic text output based on matching strings from log files

This repo contains an executable batch that relies on Powershell to look for strings/words in log files and dump those results into text files in another location.

I've put this tool to use on my servers and had some interested parties encourage me to package it for broader use. So here we are.

This repo includes example log files for testing this prior to putting it on your server. They are located in the 'testing' folder.

Moving or deleting the 'testing' folder disables <i>Test Mode</i>.

Be sure to edit the .bat file to declare your folder locations or those options won't show in the menu when you launch it.

As more mods are requested for compatibility I'll provide documentation for adding them yourself or customizing the menu options.

[<i>quad.dynns.com</i>](https://quad.dynns.com)