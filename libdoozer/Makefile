# $NetBSD: Makefile,v 1.1 2013/02/08 20:45:28 tonnerre Exp $
#

DISTNAME=	libdoozer-0.1
CATEGORIES=	wip
MASTER_SITES=	ftp://ftp.bsdprojects.net/pub/bsdprojects/libdoozer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	https://github.com/ha/doozer/
COMMENT=	C++ Client Library for the Doozer Locking Service
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gm4 gmake
USE_LANGUAGES=	c c++
GCC_REQD=	4.6

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
