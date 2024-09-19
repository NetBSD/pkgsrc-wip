# $NetBSD: Makefile,v 1.5 2012/10/03 09:10:37 asau Exp $
#

DISTNAME=	animal-0.15.0
PKGNAME=	lib${DISTNAME}
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=siptoolbox/}
EXTRACT_SUFX=	.tar.bz2
LICENSE=	gnu-gpl-v2

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://siptoolbox.sourceforge.net/
COMMENT=	Imaging and computer vision library


GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	config/animal.pc.in

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
