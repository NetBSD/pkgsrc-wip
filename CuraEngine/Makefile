# $NetBSD$

GITHUB_PROJECT=	CuraEngine
GITHUB_TAG=	4.13.1
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ultimaker/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Ultimaker/CuraEngine/
COMMENT=	Converting 3D models into g-code instructions for 3D printers
LICENSE=	gnu-agpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/protobuf/buildlink3.mk"
.include "../../wip/libArcus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
