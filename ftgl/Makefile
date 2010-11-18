# $NetBSD: Makefile,v 1.1.1.1 2010/11/18 10:05:20 ryo-on Exp $
#

DISTNAME=	ftgl-2.1.3-rc5
PKGNAME=	ftgl-2.1.3rc5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ftgl/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://sourceforge.net/projects/ftgl/
COMMENT=	C++ library of Freetype2 in OpenGL applications
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ftgl-2.1.3~rc5
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	ftgl.pc.in

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
#.include "../../devel/cppunit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
