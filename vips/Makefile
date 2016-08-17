# $NetBSD$

DISTNAME=	vips-8.3.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.vips.ecs.soton.ac.uk/supported/current/

MAINTAINER=	base@atomicules.co.uk
HOMEPAGE=	http://www.vips.ecs.soton.ac.uk/supported/current/
COMMENT=	A 2D image processing library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	vips-cpp.pc.in
PKGCONFIG_OVERRIDE+=	vips.pc.in
PKGCONFIG_OVERRIDE+=	vipsCC.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
#Note to self: This must go last
.include "../../mk/bsd.pkg.mk"
