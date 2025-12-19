# $NetBSD$

DISTNAME=	dlib-20.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=davisking/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://dlib.net/
COMMENT=	Toolkit for machine learning and data analysis applications
LICENSE=	boost-license

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

BLAS_C_INTERFACE=	yes

PKGCONFIG_OVERRIDE=	dlib/cmake_utils/dlib.pc.in

.include "../../devel/cmake/build.mk"
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../multimedia/ffmpeg8/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
