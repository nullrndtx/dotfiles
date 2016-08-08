" ------------------------------------------------
" Desc:   A dark and clean colorscheme for Vim
" Name:   darkmirror
" Author: Alex Sanchez
" Email:  kniren@gmail.com
" ------------------------------------------------
" ------------------------------------------------
" Colors
" ------------------------------------------------
    "MISC
    "foreground: #DBDFE0
    "background: #393B3E
    "BLACK
    "color0: #828D92
    "color8: #545454
    "RED
    "color1: #C05266
    "color9: #F56156
    "GREEN
    "color2: #A7E6BE
    "color10: #B1FBC5
    "YELLOW
    "color3: #56B4A9
    "color11: #FFEC7D
    "BLUE
    "color4: #3993B9
    "color12: #54ABFC
    "MAGENTA
    "color5: #C9666F
    "color13: #FC6D8A
    "CYAN
    "color6: #56B4A9
    "color14: #66D4C9
    "WHITE
    "color7: #DBDFE0
    "color15: #DBDFE0
" ------------------------------------------------

set background=dark
hi clear
if exists("syntax on")
    syntax reset
endif

let g:color_name="darkmirror"

" Normal colors
hi Normal          ctermfg=7               guifg=#DBDFE0 guibg=#393B3E gui=none
hi Ignore          ctermfg=0               guifg=#828D92               gui=none
hi Comment         ctermfg=0               guifg=#828D92               gui=none
hi LineNr          ctermfg=0               guifg=#828D92               gui=none
hi VertSplit       ctermfg=8  ctermbg=none guifg=#545454 guibg=#393B3E gui=none cterm=none 
hi Float           ctermfg=1               guifg=#C05266               gui=none
hi Include         ctermfg=6               guifg=#56B4A9               gui=none
hi Define          ctermfg=6               guifg=#56B4A9               gui=none
hi Macro           ctermfg=6               guifg=#56B4A9               gui=none
hi PreProc         ctermfg=2               guifg=#A7E6BE               gui=none
hi PreCondit       ctermfg=6               guifg=#56B4A9               gui=none
hi NonText         ctermfg=0               guifg=#828D92               gui=none
hi Directory       ctermfg=5               guifg=#56B4A9               gui=none
hi SpecialKey      ctermfg=5               guifg=#C9666F               gui=none
hi Type            ctermfg=6               guifg=#56B4A9               gui=none
hi String          ctermfg=2               guifg=#A7E6BE               gui=none
hi Constant        ctermfg=9               guifg=#F56156               gui=none
hi Special         ctermfg=10              guifg=#A7E6BE               gui=none
hi SpecialChar     ctermfg=9               guifg=#F56156               gui=none
hi Number          ctermfg=9               guifg=#F56156               gui=none
hi Identifier      ctermfg=2               guifg=#A7E6BE               gui=none
hi Conditional     ctermfg=14              guifg=#66D4C9               gui=none
hi Repeat          ctermfg=4               guifg=#3993B9               gui=none
hi Statement       ctermfg=6               guifg=#56B4A9               gui=none
hi label           ctermfg=7               guifg=#DBDFE0               gui=none
hi operator        ctermfg=6               guifg=#56B4A9               gui=none
hi keyword         ctermfg=7               guifg=#DBDFE0               gui=none
hi StorageClass    ctermfg=6               guifg=#56B4A9               gui=none
hi Structure       ctermfg=14              guifg=#66D4C9               gui=none
hi Typedef         ctermfg=2               guifg=#A7E6BE               gui=none
hi Function        ctermfg=6               guifg=#56B4A9               gui=none
hi Exception       ctermfg=2               guifg=#A7E6BE               gui=none
hi Underlined      ctermfg=8               guifg=#545454               gui=none
hi Title           ctermfg=7               guifg=#545454               gui=none
hi Tag             ctermfg=8               guifg=#545454               gui=none
hi Delimiter       ctermfg=1               guifg=#C05266               gui=none
hi SpecialComment  ctermfg=0               guifg=#828D92               gui=none
hi Boolean         ctermfg=1               guifg=#C05266               gui=none
hi MoreMsg         ctermfg=15              guifg=#DBDFE0               gui=none
hi ModeMsg         ctermfg=7               guifg=#DBDFE0               gui=none
hi Debug           ctermfg=1               guifg=#C05266               gui=none
hi MatchParen      ctermfg=7  ctermbg=0    guifg=#F56156 guibg=#DBDFE0 gui=none
hi Todo            ctermfg=5  ctermbg=none guifg=#C9666F               gui=none
hi Error           ctermfg=1  ctermbg=none 
hi ErrorMsg        ctermfg=7  ctermbg=1    guifg=#DBDFE0 guibg=#C05266 gui=none
hi WildMenu        ctermfg=7  ctermbg=0    guifg=#DBDFE0 guibg=#828D92 gui=none
hi Folded          ctermfg=0  ctermbg=none guifg=#828D92 guibg=#393B3E gui=none
hi FoldColumn      ctermfg=0  ctermbg=none guifg=#828D92 guibg=#393B3E gui=none
hi Search          ctermfg=2  ctermbg=8    guifg=#828D92 guibg=#545454 gui=none
hi IncSearch       ctermfg=7  ctermbg=5    guifg=#DBDFE0 guibg=#56B4A9 gui=none cterm=none   
hi WarningMsg      ctermfg=9  ctermbg=none guifg=#F56156               gui=none
hi Question        ctermfg=7  ctermbg=none guifg=#DBDFE0               gui=none
hi Pmenu           ctermfg=0  ctermbg=8    guifg=#828D92 guibg=#545454 gui=none
hi PmenuSel        ctermfg=8               guifg=#545454               gui=none
hi Visual          ctermfg=8  ctermbg=15   guifg=#545454 guibg=#DBDFE0 gui=none
hi StatusLine      ctermfg=8  ctermbg=15   guifg=#545454 guibg=#DBDFE0
hi StatusLineNC    ctermfg=8  ctermbg=0    guifg=#828D92 guibg=#545454  gui=none
hi CursorLine                 ctermbg=8                  guibg=#545454 gui=none cterm=none 
hi CursorLineNr               ctermbg=8    guifg=#DBDFE0 guibg=#545454 gui=none cterm=none 
hi ColorColumn                ctermbg=8                  guibg=#545454 gui=none
hi SignColumn                 ctermbg=none               guibg=#393B3E

" Vim specific
hi helpNote ctermfg=6 guifg=#56B4A9 ctermbg=none gui=none

" Diff lines
hi DiffText    ctermfg=0 ctermbg=2    guifg=#DBDFE0 gui=none
hi DiffLine    ctermfg=6 ctermbg=none guifg=#56B4A9 gui=none
hi DiffAdd     ctermfg=2 ctermbg=none guifg=#A7E6BE gui=none
hi DiffDelete  ctermfg=1 ctermbg=none guifg=#A7E6BE gui=none
hi DiffChange  ctermfg=6 ctermbg=none guifg=#56B4A9 gui=none
hi DiffRemoved ctermfg=1              guifg=#C05266

" Spell checking
if version >= 700
  hi clear SpellBad
  hi clear SpellCap
  hi clear SpellRare
  hi clear SpellLocal
  hi SpellBad   cterm=underline gui=underline
  hi SpellCap   cterm=underline gui=underline
  hi SpellRare  cterm=underline gui=underline
  hi SpellLocal cterm=underline gui=underline
endif

" Python
hi pythonString   ctermfg=2 guifg=#A7E6BE gui=none
hi pythonFunction ctermfg=7 guifg=#DBDFE0 gui=none

" HTML
hi htmlHead  ctermfg=7 guifg=#DBDFE0 gui=none
hi htmlTitle ctermfg=7 guifg=#DBDFE0 gui=none
hi htmlH1    ctermfg=7 guifg=#DBDFE0 gui=none
hi htmlH2    ctermfg=7 guifg=#DBDFE0 gui=none
hi htmlH3    ctermfg=7 guifg=#DBDFE0 gui=none
hi htmlH4    ctermfg=7 guifg=#DBDFE0 gui=none
hi htmlH5    ctermfg=7 guifg=#DBDFE0 gui=none
hi htmlH6    ctermfg=7 guifg=#DBDFE0 gui=none
hi htmlLink  ctermfg=4 guifg=#DBDFE0 gui=none

" NERDTree
hi NERDTreeRO        ctermfg=2 guifg=#A7E6BE ctermbg=none gui=none
hi NERDTreeExecFile  ctermfg=2 guifg=#A7E6BE ctermbg=none gui=none
hi NERDTreeToggleOn  ctermbg=none gui=none
hi NERDTreeToggleOff ctermbg=none gui=none

" Markdown
hi markdownH1               ctermfg=2  guifg=#A7E6BE gui=none
hi markdownH2               ctermfg=2  guifg=#A7E6BE gui=none
hi markdownH3               ctermfg=10 guifg=#B1FBC5 gui=none
hi markdownH4               ctermfg=10 guifg=#B1FBC5 gui=none
hi markdownHeadingDelimiter ctermfg=10 guifg=#B1FBC5 gui=none
hi markdownHeadingRule      ctermfg=2  guifg=#A7E6BE gui=none
hi markdownCodeBlock        ctermfg=7  guifg=#DBDFE0 gui=none
hi markdownAutomaticLink    ctermfg=1  guifg=#C05266 gui=none
hi markdownLinkText         ctermfg=6  guifg=#56B4A9 gui=none

" Mutt 
hi mailSubject   ctermfg=5 guifg=#DBDFE0 gui=none
hi mailHeaderKey ctermfg=6 guifg=#DBDFE0 gui=none

" Cursor
hi Cursor  guifg=#DBDFE0 guibg=#828D92 gui=none
hi iCursor guifg=#DBDFE0 guibg=#828D92 gui=none
hi vCursor guifg=#DBDFE0 guibg=#828D92 gui=none

" GitGutter
hi GitGutterAdd          ctermfg=2  guifg=#B1FBC5
hi GitGutterChange       ctermfg=11 guifg=#FFEC7D
hi GitGutterDelete       ctermfg=1  guifg=#C05266
hi GitGutterChangeDelete ctermfg=11 guifg=#FFEC7D

" Golang
hi goDeclaration   ctermfg=6               guifg=#56B4A9               gui=none
