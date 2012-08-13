# $NetBSD: options.mk,v 1.2 2012/08/13 21:17:41 mwilhelmy Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.polarssl
PKG_SUPPORTED_OPTIONS=		only-lib
PKG_SUGGESTED_OPTIONS=		only-lib

.include "../../mk/bsd.options.mk"

# Build and install only the shared and dynamic libs and include files,
# not the (mostly demonstrational) programs

.if !empty(PKG_OPTIONS:Monly-lib)
MAKE_ENV+=	ONLY_LIB=yes
INSTALL_ENV+=	ONLY_LIB=yes
.else
PLIST_SRC=	${PKGDIR}/PLIST ${PKGDIR}/PLIST.bin
.endif
