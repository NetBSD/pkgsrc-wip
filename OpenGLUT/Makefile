# $NetBSD: Makefile,v 1.9 2006/05/19 16:51:13 ykomatsu Exp $
#

DISTNAME=	openglut-0.6.3
PKGNAME=	OpenGLUT-0.6.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openglut/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://OpenGLUT.sourceforge.net/
COMMENT=	OpenGLUT is an open source evolution of the GLUT API

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-xf86vidmode
CONFIGURE_ARGS+=	--enable-fast

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
