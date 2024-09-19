# $NetBSD$

DISTNAME=	libgusb-0.3.5
GITHUB_TAG=	${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=hughsie/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/hughsie/libgusb/
COMMENT=	GObject wrapper for libusb1 
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config 

#.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
