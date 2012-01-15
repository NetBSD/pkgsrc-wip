# $NetBSD: Makefile,v 1.1 2012/01/15 21:46:25 bharder Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME=	tcl-expect-${EXPECT_VERSION}
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extensions to Tcl to support scripting of interactive programs

CONFLICTS+=	expect-[0-9]*

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-tclconfig=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-tclinclude=${PREFIX}/include/tcl
CONFIGURE_ARGS+=	--without-x

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR:Q}

.include "../../wip/tcl85/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
