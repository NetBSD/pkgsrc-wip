# $NetBSD$

DISTNAME=	yder-1.4.17
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=babelouest/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	olivier@biniou.info
HOMEPAGE=	https://github.com/babelouest/yder/
COMMENT=	Logging library written in C
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
CMAKE_CONFIGURE_ARGS+=	-DWITH_JOURNALD=off
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libyder.pc.in

.include "../../wip/orcania/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
