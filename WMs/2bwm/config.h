#define MOD             XCB_MOD_MASK_4       /* Super/Windows key  or check xmodmap(1) with -pm  defined in /usr/include/xcb/xproto.h */
///--Speed---///
/* Move this many pixels when moving or resizing with keyboard unless the window has hints saying otherwise.
 *0)move step slow   1)move step fast
 *2)mouse slow       3)mouse fast     */
static const uint16_t movements[] = {10,20,15,400};
/* resize by line like in mcwm -- jmbi */
static const bool     resize_by_line          = true;
/* the ratio used when resizing and keeping the aspect */
static const float    resize_keep_aspect_ratio= 1.03;
///---Offsets---///
/*0)offsetx          1)offsety
 *2)maxwidth         3)maxheight */
static const uint8_t offsets[] = {0,25,0,25};
///---Colors---///
/*0)focuscol         1)unfocuscol
 *2)fixedcol         3)unkilcol
 *4)fixedunkilcol    5)outerbordercol
 *6)emptycol         */

// dark colors
//static const char *colors[] = {"#1b1b1a","#222221","#996140","#566e6b","#7b6064","#1b1b1a","#1b1b1a"};
static const char *colors[] = {"#4f5355","#1f2325","#1f2325","#1f2325","#1f2325","#1f2325","#1f2325"};

// light colors
//static const char *colors[] = {"#548a8d","#d7dbe5","#d7dbe5","#d7dbe5","#d7dbe5","#d7dbe5","#d7dbe5"};

/*
 * If you are using a composition manager enable the COMPTON flag in the Makefile
 * (By changing -DNCOMPTON to -DCOMPTON)
 */
/* if this is set to true the inner border and outer borders colors will be swapped */
static const bool inverted_colors = false;
///---Cursor---///
/* default position of the cursor:
 * correct values are:
 * TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT, MIDDLE
 * All these are relative to the current window. */
#define CURSOR_POSITION MIDDLE
///---Borders---///
/*0) Outer border size. If you put this negative it will be a square.
 *1) Full borderwidth    2) Magnet border size
 *3) Resize border size  */

static const uint8_t borders[] = {0,4,0,0};
//static const uint8_t borders[] = {2,6,4,5};

/* Windows that won't have a border.*/
#define LOOK_INTO "WM_NAME"
static const char *ignore_names[] = {"bar", "xclock"};
///--Menus and Programs---///
static const char *menucmd[]   = { "run", NULL };
static const char *gmrun[]     = { "gmrun",NULL};
static const char *terminal[]  = { "urxvt", "-name", "sid", NULL };
static const char *click1[]    = { "xdotool","click", "1", NULL };
static const char *click2[]    = { "xdotool","click", "2", NULL };
static const char *click3[]    = { "xdotool","click", "3", NULL };
///--Custom foo---///
static void halfandcentered(const Arg *arg)
{
	Arg arg2 = {.i=TWOBWM_MAXHALF_VERTICAL_LEFT};
	maxhalf(&arg2);
	Arg arg3 = {.i=TWOBWM_TELEPORT_CENTER};
	teleport(&arg3);
}
///---Shortcuts---///
/* Check /usr/include/X11/keysymdef.h for the list of all keys
 * 0x000000 is for no modkey
 * For AZERTY keyboards XK_1...0 should be replaced by :
 *      DESKTOPCHANGE(     XK_ampersand,                     0)
 *      DESKTOPCHANGE(     XK_eacute,                        1)
 *      DESKTOPCHANGE(     XK_quotedbl,                      2)
 *      DESKTOPCHANGE(     XK_apostrophe,                    3)
 *      DESKTOPCHANGE(     XK_parenleft,                     4)
 *      DESKTOPCHANGE(     XK_minus,                         5)
 *      DESKTOPCHANGE(     XK_egrave,                        6)
 *      DESKTOPCHANGE(     XK_underscore,                    7)
 *      DESKTOPCHANGE(     XK_ccedilla,                      8)
 *      DESKTOPCHANGE(     XK_agrave,                        9)*
 */
#define DESKTOPCHANGE(K,N) \
{  MOD ,             K,              changeworkspace, {.i=N}}, \
{  MOD |SHIFT,       K,              sendtoworkspace, {.i=N}},
static key keys[] = {
    /* modifier           key            function           argument */
    // Focus to next/previous window
    {  MOD ,              XK_Tab,        focusnext,         {.i=TWOBWM_FOCUS_NEXT}},
    {  MOD |SHIFT,        XK_Tab,        focusnext,         {.i=TWOBWM_FOCUS_PREVIOUS}},
    // Kill a window
    {  MOD |SHIFT,        XK_c,          deletewin,         {}},
    // Resize a window
    {  MOD |SHIFT,        XK_k,          resizestep,        {.i=TWOBWM_RESIZE_UP}},
    {  MOD |SHIFT,        XK_j,          resizestep,        {.i=TWOBWM_RESIZE_DOWN}},
    {  MOD |SHIFT,        XK_l,          resizestep,        {.i=TWOBWM_RESIZE_RIGHT}},
    {  MOD |SHIFT,        XK_h,          resizestep,        {.i=TWOBWM_RESIZE_LEFT}},
    // Resize a window slower
    {  MOD |SHIFT|CONTROL,XK_k,          resizestep,        {.i=TWOBWM_RESIZE_UP_SLOW}},
    {  MOD |SHIFT|CONTROL,XK_j,          resizestep,        {.i=TWOBWM_RESIZE_DOWN_SLOW}},
    {  MOD |SHIFT|CONTROL,XK_l,          resizestep,        {.i=TWOBWM_RESIZE_RIGHT_SLOW}},
    {  MOD |SHIFT|CONTROL,XK_h,          resizestep,        {.i=TWOBWM_RESIZE_LEFT_SLOW}},
    // Move a window
    {  MOD ,              XK_k,          movestep,          {.i=TWOBWM_MOVE_UP}},
    {  MOD ,              XK_j,          movestep,          {.i=TWOBWM_MOVE_DOWN}},
    {  MOD ,              XK_l,          movestep,          {.i=TWOBWM_MOVE_RIGHT}},
    {  MOD ,              XK_h,          movestep,          {.i=TWOBWM_MOVE_LEFT}},
    // Move a window slower
    {  MOD |CONTROL,      XK_k,          movestep,          {.i=TWOBWM_MOVE_UP_SLOW}},
    {  MOD |CONTROL,      XK_j,          movestep,          {.i=TWOBWM_MOVE_DOWN_SLOW}},
    {  MOD |CONTROL,      XK_l,          movestep,          {.i=TWOBWM_MOVE_RIGHT_SLOW}},
    {  MOD |CONTROL,      XK_h,          movestep,          {.i=TWOBWM_MOVE_LEFT_SLOW}},
    // Teleport the window to an area of the screen.
    // Center:
    {  MOD ,              XK_g,          teleport,          {.i=TWOBWM_TELEPORT_CENTER}},
    // Center y:
    {  MOD |SHIFT,        XK_g,          teleport,          {.i=TWOBWM_TELEPORT_CENTER_Y}},
    // Center x:
    {  MOD |CONTROL,      XK_g,          teleport,          {.i=TWOBWM_TELEPORT_CENTER_X}},
    // Top left:
    {  MOD ,              XK_y,          teleport,          {.i=TWOBWM_TELEPORT_TOP_LEFT}},
    // Top right:
    {  MOD ,              XK_u,          teleport,          {.i=TWOBWM_TELEPORT_TOP_RIGHT}},
    // Bottom left:
    {  MOD ,              XK_b,          teleport,          {.i=TWOBWM_TELEPORT_BOTTOM_LEFT}},
    // Bottom right:
    {  MOD ,              XK_n,          teleport,          {.i=TWOBWM_TELEPORT_BOTTOM_RIGHT}},
    // Resize while keeping the window aspect
    {  MOD ,              XK_Home,       resizestep_aspect, {.i=TWOBWM_RESIZE_KEEP_ASPECT_GROW}},
    {  MOD ,              XK_End,        resizestep_aspect, {.i=TWOBWM_RESIZE_KEEP_ASPECT_SHRINK}},
    // Full screen window without borders
    {  MOD ,              XK_x,         maximize,           {.i=TWOBWM_FULLSCREEN_OVERRIDE_OFFSETS}},
    //Full screen window without borders overiding offsets
    {  MOD |SHIFT ,       XK_x,          maximize,          {.i=TWOBWM_FULLSCREEN}},
    // Maximize vertically
    {  MOD ,              XK_m,          maxvert_hor,       {.i=TWOBWM_MAXIMIZE_VERTICALLY}},
    // Maximize horizontally
    {  MOD |SHIFT,        XK_m,          maxvert_hor,       {.i=TWOBWM_MAXIMIZE_HORIZONTALLY}},
    // Maximize and move
    // vertically left
    {  MOD |SHIFT,        XK_y,          maxhalf,           {.i=TWOBWM_MAXHALF_VERTICAL_LEFT}},
    // vertically right
    {  MOD |SHIFT,        XK_u,          maxhalf,           {.i=TWOBWM_MAXHALF_VERTICAL_RIGHT}},
    // horizontally left
    {  MOD |SHIFT,        XK_b,          maxhalf,           {.i=TWOBWM_MAXHALF_HORIZONTAL_BOTTOM}},
    // horizontally right
    {  MOD |SHIFT,        XK_n,          maxhalf,           {.i=TWOBWM_MAXHALF_HORIZONTAL_TOP}},
    //fold half vertically
    {  MOD |SHIFT|CONTROL,XK_y,          maxhalf,           {.i=TWOBWM_MAXHALF_FOLD_VERTICAL}},
    //fold half horizontally
    {  MOD |SHIFT|CONTROL,XK_b,          maxhalf,           {.i=TWOBWM_MAXHALF_FOLD_HORIZONTAL}},
    //unfold vertically
    {  MOD |SHIFT|CONTROL,XK_u,          maxhalf,           {.i=TWOBWM_MAXHALF_UNFOLD_VERTICAL}},
    //unfold horizontally
    {  MOD |SHIFT|CONTROL,XK_n,          maxhalf,           {.i=TWOBWM_MAXHALF_UNFOLD_HORIZONTAL}},
    // Next/Previous screen
    //{  MOD ,              XK_comma,      changescreen,      {.i=TWOBWM_NEXT_SCREEN}},
    //{  MOD ,              XK_period,     changescreen,      {.i=TWOBWM_PREVIOUS_SCREEN}},
    // Raise or lower a window
    {  MOD ,              XK_r,          raiseorlower,      {}},
    // Next/Previous workspace
    {  MOD ,              XK_comma,           prevworkspace,     {}},
    {  MOD ,              XK_period,          nextworkspace,     {}},
    // Move to Next/Previous workspace
    {  MOD |SHIFT ,       XK_comma,          sendtoprevworkspace,{}},
    {  MOD |SHIFT ,       XK_period,         sendtonextworkspace,{}},
    // Iconify the window
    // {  MOD ,              XK_i,          hide,              {}},
    // Make the window unkillable
    {  MOD ,              XK_a,          unkillable,        {}},
    // Make the window appear always on top
    {  MOD,               XK_t,          always_on_top,     {}},
    // Make the window stay on all workspaces
    {  MOD ,              XK_f,          fix,               {}},
    // Move window with arrow keys
    {  MOD ,              XK_Up,         movestep,           {.i=TWOBWM_MOVE_UP}},
    {  MOD ,              XK_Down,       movestep,           {.i=TWOBWM_MOVE_DOWN}},
    {  MOD ,              XK_Right,      movestep,           {.i=TWOBWM_MOVE_RIGHT}},
    {  MOD ,              XK_Left,       movestep,           {.i=TWOBWM_MOVE_LEFT}},
    // Move window with arrow keys slower
    {  MOD |CONTROL,        XK_Up,         movestep,         {.i=TWOBWM_MOVE_UP_SLOW}},
    {  MOD |CONTROL,        XK_Down,       movestep,         {.i=TWOBWM_MOVE_DOWN_SLOW}},
    {  MOD |CONTROL,        XK_Right,      movestep,         {.i=TWOBWM_MOVE_RIGHT_SLOW}},
    {  MOD |CONTROL,        XK_Left,       movestep,         {.i=TWOBWM_MOVE_LEFT_SLOW}},
	// Resize window with arrow keys
    {  MOD |SHIFT,        XK_Up,          resizestep,        {.i=TWOBWM_RESIZE_UP}},
    {  MOD |SHIFT,        XK_Down,        resizestep,        {.i=TWOBWM_RESIZE_DOWN}},
    {  MOD |SHIFT,        XK_Right,       resizestep,        {.i=TWOBWM_RESIZE_RIGHT}},
    {  MOD |SHIFT,        XK_Left,        resizestep,        {.i=TWOBWM_RESIZE_LEFT}},
    // Resize window with arrow keys slow
    {  MOD |SHIFT|CONTROL, XK_Up,          resizestep,       {.i=TWOBWM_RESIZE_UP_SLOW}},
    {  MOD |SHIFT|CONTROL, XK_Down,        resizestep,       {.i=TWOBWM_RESIZE_DOWN_SLOW}},
    {  MOD |SHIFT|CONTROL, XK_Right,       resizestep,       {.i=TWOBWM_RESIZE_RIGHT_SLOW}},
    {  MOD |SHIFT|CONTROL, XK_Left,        resizestep,       {.i=TWOBWM_RESIZE_LEFT_SLOW}},
    // Start programs
    {  MOD |SHIFT,        XK_Return,     start,              {.com = terminal}},
    {  MOD ,              XK_w,          start,              {.com = menucmd}},
    //{  MOD |SHIFT,        XK_w,          start,              {.com = gmrun}},
    // Exit or restart 2bwm
    {  MOD |CONTROL,      XK_q,          twobwm_exit,        {.i=0}},
    {  MOD |CONTROL,      XK_r,          twobwm_restart,     {.i=0}},
    {  MOD ,              XK_space,      halfandcentered,    {.i=0}},
   // Fake clicks using xdotool
   // {  MOD |CONTROL,      XK_Up,         start,            {.com = click1}},
   // {  MOD |CONTROL,      XK_Down,       start,            {.com = click2}},
   // {  MOD |CONTROL,      XK_Right,      start,            {.com = click3}},

    // Change current workspace
       DESKTOPCHANGE(     XK_1,                             0)
       DESKTOPCHANGE(     XK_2,                             1)
       DESKTOPCHANGE(     XK_3,                             2)
       DESKTOPCHANGE(     XK_4,                             3)
       DESKTOPCHANGE(     XK_5,                             4)
       DESKTOPCHANGE(     XK_6,                             5)
       DESKTOPCHANGE(     XK_7,                             6)
       DESKTOPCHANGE(     XK_8,                             7)
       DESKTOPCHANGE(     XK_9,                             8)
       DESKTOPCHANGE(     XK_0,                             9)
};
static Button buttons[] = {
    {  MOD        ,XCB_BUTTON_INDEX_1,     mousemotion,   {.i=TWOBWM_MOVE}},
    {  MOD        ,XCB_BUTTON_INDEX_3,     mousemotion,   {.i=TWOBWM_RESIZE}},
    {  MOD|CONTROL,XCB_BUTTON_INDEX_3,     start,         {.com = menucmd}},
    {  MOD|SHIFT,  XCB_BUTTON_INDEX_1,     changeworkspace, {.i=0}},
    {  MOD|SHIFT,  XCB_BUTTON_INDEX_3,     changeworkspace, {.i=1}},
    {  MOD|ALT,    XCB_BUTTON_INDEX_1,     changescreen,    {.i=1}},
    {  MOD|ALT,    XCB_BUTTON_INDEX_3,     changescreen,    {.i=0}}
};
