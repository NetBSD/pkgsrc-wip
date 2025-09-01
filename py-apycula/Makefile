# $NetBSD$

DISTNAME=	apycula-0.24
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/apycula/}

MAINTAINER=	pkgsrc-users@NetBSD.org
# Yep, the name in github is apicula, not apycula...
HOMEPAGE=	https://github.com/YosysHQ/apicula
COMMENT=	Open Source tools for Gowin FPGAs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-crc>=0:../../security/py-crc

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
