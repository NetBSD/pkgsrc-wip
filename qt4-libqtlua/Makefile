# $NetBSD: Makefile,v 1.1 2014/10/15 17:53:35 nros Exp $

DISTNAME=	libqtlua-2.0
PKGNAME=	qt4-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	http://download.savannah.gnu.org/releases/libqtlua/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/libqtlua/
COMMENT=	Lua alternative to the QtScript module
LICENSE=	gnu-gpl-v3 OR gnu-lgpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DINSTALL_BIN=${QTDIR}/bin
CMAKE_ARGS+=	-DINSTALL_INC=${QTDIR}/include
CMAKE_ARGS+=	-DINSTALL_LIB=${QTDIR}/lib

.include "../../lang/lua51/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
