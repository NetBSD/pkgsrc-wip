# $NetBSD: Makefile,v 1.1.1.1 2011/02/24 15:12:08 pallegra Exp $
#

DISTNAME=	irrlicht-1.7.2
CATEGORIES=	graphics games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=irrlicht/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://irrlicht.sourceforge.net/
COMMENT=	open source high performance realtime 3D engine
#LICENSE=	png-license #irrlicht-license ?

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

MAKE_ENV=	NDEBUG=1
BUILD_DIRS=	source/Irrlicht
BUILD_TARGET=	sharedlib

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
