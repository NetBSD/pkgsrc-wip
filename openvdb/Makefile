# $NetBSD$

DISTNAME=	openvdb-${PKGVERSION}
PKGVERSION=	11.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_PROJECT=	openvdb
GITHUB_TAG=	v${PKGVERSION}

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://www.openvdb.org/
COMMENT=	Efficient storage and manipulation of sparse volumetric data
LICENSE=	mpl-2.0

USE_LANGUAGES=	c c++
GCC_REQD+=	10	# actually needs 9.3.1, but we don't have that
USE_TOOLS+=	gmake pkg-config
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	cd ${WRKSRC} && mkdir build

.include "../../devel/blosc/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/jemalloc/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
