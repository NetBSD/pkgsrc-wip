# $NetBSD: Makefile,v 1.2 2004/08/07 10:23:49 thomasklausner Exp $
#

DISTNAME=	openglut-0.6.2
PKGNAME=	OpenGLUT-0.6.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openglut/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://OpenGLUT.sourceforge.net/
COMMENT=	OpenGLUT is an open source evolution of the GLUT API

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_X11=	yes

CONFIGURE_ARGS= --disable-xf86vidmode --enable-fast

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
