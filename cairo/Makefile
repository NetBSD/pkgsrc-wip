# $NetBSD: Makefile,v 1.3 2004/01/19 21:08:46 marc Exp $
#

DISTNAME=	cairo-0.1.17
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
.include "../../graphics/freetype2/buildlink2.mk"

.include "../../fonts/Xft2/buildlink2.mk"
.include "../../wip/libpixman/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
