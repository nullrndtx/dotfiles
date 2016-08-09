#!/bin/bash

# load terminal colors
xrdb ~/.x/xres &

# pulseaudio daemon
pulseaudio --start &

# fix x pointer
xsetroot -cursor_name left_ptr &

# reduce brightness
xcalib ~/.x230.icm &

# compositor
# compton &

# fix java crash
wmname LG3D &

# low pointer
LowMouse &

# load bitmap fonts
xset +fp ~/.fonts &
xset fp rehash &

# daemon apps
thunar --daemon &
mpd &

# Set wallpaper
feh --bg-tile ~/.bg &

# panel
# /home/rndtx/etc/musicbar/main.sh &

# hotkeys
#sxhkd -c ~/.config/sxhkd/sxhkdrc-wmrc &
xbindkeys &

# volumeicon
# volumeicon &

# Window Manager
dwmstatus &
#status-bash &
exec dwm
