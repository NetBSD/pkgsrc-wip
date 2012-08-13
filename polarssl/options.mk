# $NetBSD: options.mk,v 1.1 2012/08/13 20:41:29 mwilhelmy Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.polarssl
PKG_SUPPORTED_OPTIONS=		only-lib tests
PKG_SUGGESTED_OPTIONS=		only-lib tests

.include "../../mk/bsd.options.mk"

# Build and install only the shared and dynamic libs and include files,
# not the (mostly demonstrational) programs

.if !empty(PKG_OPTIONS:Monly-lib)
MAKE_ENV+=	ONLY_LIB=yes
INSTALL_ENV+=	ONLY_LIB=yes
.else
PLIST_SRC=	${PKGDIR}/PLIST ${PKGDIR}/PLIST.bin
.endif

# Run the testsuite; disabling yields in much faster builds, but is discouraged
# for everything other than packaging purposes, because this is security software
.if !empty(PKG_OPTIONS:Mtests)
MAKE_ENV+=	RUN_TESTS=yes
INSTALL_ENV+=	RUN_TESTS=yes
.endif
