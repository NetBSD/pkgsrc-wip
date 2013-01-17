# $NetBSD: Makefile,v 1.3 2013/01/17 13:20:35 othyro Exp $
#

DISTNAME=	ftgl-2.1.3-rc5
PKGNAME=	${DISTNAME:S/-r/r/1}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ftgl/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://sourceforge.net/projects/ftgl/
COMMENT=	C++ library of Freetype2 in OpenGL applications
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/ftgl-2.1.3~rc5
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake gsed pkg-config
USE_LANGUAGES=	c c++ fortran
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	ftgl.pc.in

BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
.include "../../devel/cppunit/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
