# $NetBSD: Makefile,v 1.1.1.1 2007/11/11 01:31:24 pmatias Exp $
#

DISTNAME=	animal-0.15.0
PKGNAME=	lib${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=siptoolbox/}
EXTRACT_SUFX=	.tar.bz2

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
