PKG_OPTIONS_VAR=	PKG_OPTIONS.0ad
PKG_SUPPORTED_OPTIONS+=	tests

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mtests}
CONFIGURE_TESTS?=		--with-tests
.else
CONFIGURE_TESTS?=		--without-tests
.endif
