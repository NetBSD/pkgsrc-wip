# $NetBSD: Makefile,v 1.36 2025/11/16 07:58:04 adam Exp $

DISTNAME=	asyncclick-8.3.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncclick/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/asyncclick/
COMMENT=	Composable command line interface toolkit, async fork
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core

PYTHON_VERSIONS_INCOMPATIBLE=	310

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
