# $NetBSD: Makefile,v 1.10 2008/05/29 17:27:10 tnn2 Exp $
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
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-xf86vidmode
CONFIGURE_ARGS+=	--enable-fast

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
