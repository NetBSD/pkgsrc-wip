# $NetBSD$

DISTNAME=	sphinxcontrib-svg2pdfconverter-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-svg2pdfconverter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/missinglinkelectronics/sphinxcontrib-svg2pdfconverter
COMMENT=	Sphinx SVG to PDF converter extension
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.6.3:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-sphinx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
