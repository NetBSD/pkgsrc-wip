PKG_OPTIONS_VAR=	PKG_OPTIONS.tcltk85
PKG_SUPPORTED_OPTIONS=	threaded memdebug
PKG_SUGGESTED_OPTIONS=	threaded

.include "../../mk/bsd.options.mk"

.  if !empty(PKG_OPTIONS:Mmemdebug)
CONFIGURE_ARGS+=	--enable-symbols=mem
.  endif

.  if !empty(PKG_OPTIONS:Mthreaded)
CONFIGURE_ARGS+=	--enable-threads=on
.  else
CONFIGURE_ARGS+=	--enable-threads=off
.  endif
