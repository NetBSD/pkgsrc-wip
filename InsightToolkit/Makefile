# $NetBSD$

DISTNAME=	InsightToolkit-5.4.7
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=InsightSoftwareConsortium/}
GITHUB_PROJECT=	ITK
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/InsightSoftwareConsortium/ITK/
COMMENT=	Open-source, cross-platform library for image analysis
#LICENSE=	# TODO: (see mk/license.mk)

CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_HDF5=on

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

CFLAGS+=	-Wno-implicit-function-declaration

PKGCONFIG_OVERRIDE+=	Modules/ThirdParty/GoogleTest/src/itkgoogletest/googletest/cmake/gtest.pc.in
PKGCONFIG_OVERRIDE+=	Modules/ThirdParty/GoogleTest/src/itkgoogletest/googletest/cmake/gtest_main.pc.in
#PKGCONFIG_OVERRIDE+=	Modules/ThirdParty/HDF5/src/itkhdf5/config/libhdf5.pc.in

.include "../../devel/cmake/build.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/hdf5-c++/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
