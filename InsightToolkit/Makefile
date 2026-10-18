# $NetBSD$

DISTNAME=	InsightToolkit-5.4.7
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=InsightSoftwareConsortium/}
GITHUB_PROJECT=	ITK
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/InsightSoftwareConsortium/ITK/
COMMENT=	Open-source, cross-platform library for image analysis
#LICENSE=	# TODO: (see mk/license.mk)

TOOL_DEPENDS+=	googletest>=0:../../devel/googletest

#CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_DCMTK=on
CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_DOUBLECONVERSION=on
CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_EIGEN=on
CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_EXPAT=on
CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_FFTW=on
# TODO: leads to link error, fix
#CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_GDCM=on
CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_HDF5=on
CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_JPEG=on
CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_LIBRARIES=on
CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_PNG=on
CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_TIFF=on
#CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_VXL=on
CMAKE_CONFIGURE_ARGS+=	-DITK_USE_SYSTEM_ZLIB=on
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=on

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

CFLAGS+=	-Wno-implicit-function-declaration

# fix library name for pkgsrc
BUILDLINK_TRANSFORM+=	opt:-lhdf5_cpp-shared:-lhdf5_cpp

# due to patch-Modules_Core_Common_include_itkMemoryUsageObserver.h
post-install:
	${RM} ${DESTDIR}${PREFIX}/include/ITK-5.4/itkMemoryUsageObserver.h.orig

# vxl?
# dcmtk?
.include "../../devel/cmake/build.mk"
.include "../../archivers/libaec/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/hdf5-c++/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/vtk/buildlink3.mk"
.include "../../math/double-conversion/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
#.include "../../wip/gdcm/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
