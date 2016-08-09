# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi

# Colors
RS="\[\033[0m\]"    # reset
HC="\[\033[1m\]"    # hicolor
UL="\[\033[4m\]"    # underline
INV="\[\033[7m\]"   # inverse background and foreground
FBLK="\[\033[30m\]" # foreground black
FRED="\[\033[31m\]" # foreground red
FGRN="\[\033[32m\]" # foreground green
FYEL="\[\033[33m\]" # foreground yellow
FBLE="\[\033[34m\]" # foreground blue
FMAG="\[\033[35m\]" # foreground magenta
FCYN="\[\033[36m\]" # foreground cyan
FWHT="\[\033[37m\]" # foreground white
BBLK="\[\033[40m\]" # background black
BRED="\[\033[41m\]" # background red
BGRN="\[\033[42m\]" # background green
BYEL="\[\033[43m\]" # background yellow
BBLE="\[\033[44m\]" # background blue
BMAG="\[\033[45m\]" # background magenta
BCYN="\[\033[46m\]" # background cyan
BWHT="\[\033[47m\]" # background white

# Prompt
PS1="
$HC$FCYN\@ $FYEL \W  $RS"

# Auto-CD
shopt -s autocd

# Path
PATH=~/bin:$PATH
PATH=~/etc/scripts:$PATH
PATH=~/.config/bspwm:$PATH
#PATH=~/etc/wmtls:$PATH
PATH=~/.config/wmrc:$PATH
PATH=/mnt/WINDOWSDATA/ANDROID/LINUX/android-sdk/platform-tools:$PATH

# Set all the aliases
. $HOME/.aliases

# Base16-Shell
#BASE16_SHELL="$HOME/.config/base16-shell/scripts/base16-default-dark.sh"
#[[ -s $BASE16_SHELL ]] && source $BASE16_SHELL ]]

# rvm
source ~/.rvm/scripts/rvm

# Golang
export GOPATH=~/go
export PATH=$PATH:~/go/bin

export TERM=xterm-256color
eval $(dircolors -b $HOME/.dircolors)

# PERL
PATH="/home/rndtx/perl5/bin${PATH:+:${PATH}}"; export PATH;
PERL5LIB="/home/rndtx/perl5/lib/perl5${PERL5LIB:+:${PERL5LIB}}"; export PERL5LIB;
PERL_LOCAL_LIB_ROOT="/home/rndtx/perl5${PERL_LOCAL_LIB_ROOT:+:${PERL_LOCAL_LIB_ROOT}}"; export PERL_LOCAL_LIB_ROOT;
PERL_MB_OPT="--install_base \"/home/rndtx/perl5\""; export PERL_MB_OPT;
PERL_MM_OPT="INSTALL_BASE=/home/rndtx/perl5"; export PERL_MM_OPT;
