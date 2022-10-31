# $NetBSD$

DISTNAME=	nextpnr-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=YosysHQ/}
GITHUB_PROJECT=	nextpnr
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	lloyd@must-have-coffee.gen.nz
HOMEPAGE=	https://github.com/YosysHQ/nextpnr
COMMENT=	Portable FPGA place and route tool
LICENSE=	isc

# Need an option for QT

USE_LANGUAGES=	c c++14
USE_CMAKE=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"

.include "../../lang/python/application.mk"

.include "../../math/eigen3/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
