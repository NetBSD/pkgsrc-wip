# $NetBSD: Makefile,v 1.1.1.1 2003/11/27 19:08:14 marc Exp $
#

DISTNAME=	cairo-0.1.13
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://cairographics.org/snapshots/
COMMENT=	Vector graphics library with cross-device output support

USE_X11=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/cairo.pc.in
GNU_CONFIGURE=		yes

BUILDLINK_DEPENDS.freetype2=  freetype2>=2.1.5

.include "../../fonts/Xft2/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../wip/libic/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
