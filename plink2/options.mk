PKG_OPTIONS_VAR=	PKG_OPTIONS.plink2
PKG_SUPPORTED_OPTIONS=	native

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnative)
CFLAGS+=	-march=native
.endif
