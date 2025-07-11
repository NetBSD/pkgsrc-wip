# $NetBSD$

DISTNAME=	libudev-bsd-0.6.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kikadf/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/kikadf/libudev-bsd/
COMMENT=	Libudev compatible interface for BSD systems
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../wip/ndevd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
