# $NetBSD$

DISTNAME=	openvdb-${PKGVERSION}
PKGVERSION=	7.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_PROJECT=	openvdb
GITHUB_TAG=	v${PKGVERSION}

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://www.openvdb.org/
COMMENT=	Library for the efficient storage and manipulation of sparse volumetric data
LICENSE=	mpl-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake cmake pkg-config
USE_CMAKE=	yes
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	cd ${WRKSRC} && mkdir build

.include "../../devel/blosc/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/ilmbase/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../wip/threadingbuildingblocks/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
