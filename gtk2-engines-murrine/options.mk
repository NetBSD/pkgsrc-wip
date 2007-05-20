PKG_OPTIONS_VAR=		PKG_OPTIONS.gtk2-engines-murrine
PKG_SUPPORTED_OPTIONS=		animation animationtoleft macmenu

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# Package-specific option-handling

##
## animation support
##
.if !empty(PKG_OPTIONS:Manimation)
CONFIGURE_ARGS+=        --enable-animation
.else
CONFIGURE_ARGS+=        --disable-animation
.endif

##
## progressbar animation from right to left
##
.if !empty(PKG_OPTIONS:Manimationtoleft)
CONFIGURE_ARGS+=        --enable-animationtoleft
.else
CONFIGURE_ARGS+=        --disable-animationtoleft
.endif

##
## mac menubar
##
.if !empty(PKG_OPTIONS:Mmacmenu)
CONFIGURE_ARGS+=        --enable-macmenu
.else
CONFIGURE_ARGS+=        --disable-macmenu
.endif
