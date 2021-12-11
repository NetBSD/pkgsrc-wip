# $NetBSD$

DISTNAME=	suscan-0.2.0git
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=BatchDrake/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	4ad53ffd4e6a3733e7bc72fb73d0bf6294a64aaf

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
