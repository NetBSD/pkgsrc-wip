# $NetBSD: Makefile,v 1.2 2012/01/15 22:15:37 bharder Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME=	tcl-expect-${EXPECT_VERSION}
DISTNAME=	expect5.45
MASTER_SITES=	http://downloads.sourceforge.net/project/expect/Expect/5.45/
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
