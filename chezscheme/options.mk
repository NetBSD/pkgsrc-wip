PKG_OPTIONS_VAR=	PKG_OPTIONS.chezscheme
PKG_SUPPORTED_OPTIONS=	threads
PKG_SUGGESTED_OPTIONS=	threads

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+= --threads
THR=	t
.endif
