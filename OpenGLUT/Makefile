# $NetBSD: Makefile,v 1.1.1.1 2004/05/26 13:32:23 thomasklausner Exp $
#

DISTNAME=	openglut-0.6.1
PKGNAME=        OpenGLUT-0.6.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openglut/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://OpenGLUT.sourceforge.net/
COMMENT=	OpenGLUT is an open source evolution of the GLUT API

BUILD_DEPENDS+=	gawk-[0-9]*:../../lang/gawk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_X11=	yes

# Add --enable-fast to CONFIGURE_ARGS for OpenGLUT 0.6.2 or later.
# For 0.6.1, the effect is achieved with a couple of patches
#
CONFIGURE_ARGS= --disable-xf86vidmode

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
