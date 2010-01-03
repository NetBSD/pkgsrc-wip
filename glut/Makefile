# $NetBSD: Makefile,v 1.10 2010/01/03 15:08:44 pallegra Exp $
#

.include "../../wip/gl/Makefile.common"

PKGNAME=	${COMPONENT}-${MESA_PKGVERSION}
CATEGORIES=	graphics
EXTRACT_SUFX=	.tar.bz2

COMPONENT=	glut

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://www.mesa3d.org/
COMMENT=	GLUT Graphics library similar to SGI's OpenGL
#LICENSE=	mark-license

pre-build:
	cd ${WRKSRC} && ${MKDIR} -p lib

BUILD_DIRS=		src/glut/glx
BUILD_TARGET=		default

INSTALL_DIRS=		src/glut/glx

.include "../../wip/gl/buildlink3.mk"
.include "../../wip/glu/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
