# $NetBSD: Makefile,v 1.1 2022/02/07 15:19:31 wiz Exp $

DISTNAME=	furo-2022.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/furo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/furo/
COMMENT=	Clean customisable Sphinx documentation theme
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sphinx>=2.0:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-theme-builder-[0-9]*:../../wip/py-sphinx-theme-builder

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
