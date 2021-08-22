# $NetBSD$

DISTNAME=	talk2stat-0.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/talk2stat/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.org/project/talk2stat/
COMMENT=	Python package to communicate with statistical software
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE+=	27

DEPENDS+=	${PYPKGPREFIX}-pexpect>=4.8.0:../../devel/py-pexpect


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
