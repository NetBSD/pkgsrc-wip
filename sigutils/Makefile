# $NetBSD$

DISTNAME=	sigutils-0.1.0git
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=BatchDrake/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	0d434d697bd7ac94e6b51448d31d1e433debe360

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://github.com/BatchDrake/sigutils/
COMMENT=	Digital signal processing library
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
