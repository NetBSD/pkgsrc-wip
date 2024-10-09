# $NetBSD$

DISTNAME=	sphinxcontrib-apidoc-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-apidoc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/sphinxcontrib-apidoc/
COMMENT=	Sphinx extension for running sphinx-apidoc on each build
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
