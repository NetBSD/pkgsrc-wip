# $NetBSD$

DISTNAME=	country_converter-0.7.2
PKGNAME=	${PYPKGPREFIX}-country-converter-0.7.2
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/country_converter/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/konstantinstadler/country_converter
COMMENT=	Converting country names between different classifications schemes
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=	27

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.17.0:../../math/py-pandas

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
