# $NetBSD$

DISTNAME=	qtaccountsservice-0.6.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hawaii-desktop/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hawaii-desktop/qtaccountsservice/
COMMENT=	Qt-style API for freedesktop.org's AccountsService DBus service
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND gnu-fdl-v1.3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../wip/extra-cmake-modules/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
