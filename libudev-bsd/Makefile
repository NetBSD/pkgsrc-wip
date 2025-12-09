# $NetBSD$

DISTNAME=	libudev-bsd-0.6.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kikadf/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/kikadf/libudev-bsd/
COMMENT=	Libudev compatible interface for BSD systems
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config

ONLY_FOR_PLATFORM=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	OpenBSD-*-*
ONLY_FOR_PLATFORM+=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-*

.include "../../mk/bsd.prefs.mk"

.include "../../devel/meson/build.mk"
.if ${OPSYS} == "NetBSD"
.include "../../wip/ndevd/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
