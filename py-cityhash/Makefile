# $NetBSD$

DISTNAME=	cityhash-0.4.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_PROJECT=	python-cityhash
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cityhash/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/escherba/cityhash
COMMENT=	Python wrapper for FarmHash and CityHash
LICENSE=	modified-bsd


TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=68:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-cpuinfo>=9.0.0:../../sysutils/py-cpuinfo

DEPENDS+=	cityhash-[0-9]*:../../textproc/cityhash

USE_LANGUAGES=	c c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
