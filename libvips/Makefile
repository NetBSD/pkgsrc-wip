# $NetBSD$

DISTNAME=	vips-8.14.4
PKGNAME=	lib${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=libvips/}
GITHUB_PROJECT=	libvips
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	base@atomicules.co.uk
HOMEPAGE=	https://libvips.github.io/libvips/
COMMENT=	Libvips is a demand-driven, horizontally threaded image processing lib
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		pkg-config msgfmt xgettext
USE_LANGUAGES=		c c++
PYTHON_FOR_BUILD_ONLY=  tool

PKGCONFIG_OVERRIDE_STAGE=   pre-install
PKGCONFIG_OVERRIDE+=        output/meson-private/vips-cpp.pc
PKGCONFIG_OVERRIDE+=        output/meson-private/vips.pc

.include "../../devel/meson/build.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
#Note to self: This must go last
.include "../../mk/bsd.pkg.mk"
