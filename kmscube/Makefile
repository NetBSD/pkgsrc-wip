# $NetBSD: $

DISTNAME=	kmscube
CATEGORIES=	graphics
MASTER_SITES=	https://gitlab.freedesktop.org/mesa/kmscube/-/archive/master/kmscube-master/
GIT_TAG=	467e86c5cbeb2a2051b31ce2c240d6ddf5bc3112
WRKSRC=		${WRKDIR}/kmscube-master-${GIT_TAG}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.freedesktop.org/mesa/kmscube/
COMMENT=	Example KMS/GBM/EGL application
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS=	ninja-build-[0-9]*:../../devel/ninja-build
USE_TOOLS+=	pkg-config

USE_LANGUAGES+=		c

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

.include "../../devel/meson/build.mk"
.include "../../devel/cmake/build.mk"

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
