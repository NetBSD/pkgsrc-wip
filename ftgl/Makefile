# $NetBSD: Makefile,v 1.4 2015/08/07 13:20:43 thomasklausner Exp $

DISTNAME=	ftgl-2.1.3-rc5
PKGNAME=	${DISTNAME:S/-r/r/1}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ftgl/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://sourceforge.net/projects/ftgl/
COMMENT=	C++ library of Freetype2 in OpenGL applications
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	doxygen>=1.8.9.1:../../devel/doxygen

WRKSRC=		${WRKDIR}/ftgl-2.1.3~rc5
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake gsed pkg-config
USE_LANGUAGES=	c c++ fortran
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	ftgl.pc.in

.include "../../devel/cppunit/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
