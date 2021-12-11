# $NetBSD$

DISTNAME=	sigutils-0.2.0git
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=BatchDrake/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	eb6436559ef2d182c4099244fcfd4be50232c15e

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
