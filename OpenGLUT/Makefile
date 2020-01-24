# $NetBSD: Makefile,v 1.12 2014/10/09 14:06:26 thomasklausner Exp $
#

DISTNAME=	openglut-0.6.3
PKGNAME=	OpenGLUT-0.6.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openglut/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://OpenGLUT.sourceforge.net/
COMMENT=	OpenGLUT is an open source evolution of the GLUT API

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-xf86vidmode
CONFIGURE_ARGS+=	--enable-fast

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
