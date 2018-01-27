# $NetBSD$

DISTNAME=	vips-8.6.1
PKGNAME=	lib${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=jcupitt/}

MAINTAINER=	base@atomicules.co.uk
HOMEPAGE=	http://jcupitt.github.io/libvips/
COMMENT=	Libvips is a demand-driven, horizontally threaded image processing lib
LICENSE=	gnu-lgpl-v2.1

GITHUB_PROJECT=	libvips
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

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
.include "../../graphics/libexif/buildlink3.mk"
#Note to self: This must go last
.include "../../mk/bsd.pkg.mk"
