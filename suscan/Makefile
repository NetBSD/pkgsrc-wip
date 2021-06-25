# $NetBSD$

DISTNAME=	suscan-0.1.0git
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=BatchDrake/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	4f6ede2fd62d0992e582e5efa436bbdb8d49e8c1

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://github.com/BatchDrake/suscan/
COMMENT=	Realtime DSP library
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

CFLAGS.NetBSD+=	-DCLOCK_MONOTONIC_RAW=CLOCK_MONOTONIC

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../wip/sigutils/buildlink3.mk"
.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
