# $NetBSD$

DISTNAME=	delegator.py-0.1.1
PKGNAME=	${PYPKGPREFIX}-delegator-0.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=d/delegator.py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/delegator.py
COMMENT=	Subprocesses for Humans 2.0
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pexpect>=4.1.0:../../devel/py-pexpect

WHEEL_NAME=	${DISTNAME:S/./_/}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
