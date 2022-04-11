# $NetBSD: Makefile,v 1.17 2022/03/31 21:48:45 wiz Exp $

DISTNAME=	pytest-vcr-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-vcr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-asyncio
COMMENT=	py-test plugin for managing VCR.py cassettes
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test>=6.1.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-vcrpy>=4.1.1:../../wip/py-vcrpy

PYTHON_VERSIONS_INCOMPATIBLE=	27


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
