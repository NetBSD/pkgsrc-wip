PKG_OPTIONS_VAR=	PKG_OPTIONS.tcltk86
PKG_SUPPORTED_OPTIONS=	nothread memdebug
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.  if !empty(PKG_OPTIONS:Mmemdebug)
CONFIGURE_ARGS+=	--enable-symbols=mem
.  endif

.  if !empty(PKG_OPTIONS:Mnothread)
CONFIGURE_ARGS+=	--enable-threads=off
.  else
PTHREAD_OPTS?=native
.include "../../mk/pthread.buildlink3.mk"
.  endif
