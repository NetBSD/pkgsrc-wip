PKG_OPTIONS_VAR=        PKG_OPTIONS.radare
PKG_SUPPORTED_OPTIONS=  debugger gui

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebugger)
CONFIGURE_ARGS+=        --with-debugger
.endif

.if !empty(PKG_OPTIONS:Mgui)
CONFIGURE_ARGS+=        --with-gui
.include "../../x11/gtk2/buildlink3.mk"
.endif
