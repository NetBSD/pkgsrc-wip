# $NetBSD$

DISTNAME=	python-registry-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/a4/82/c9ae8e9764eae863a4d63c05d5f2d767e392b523c2976c16c56f9a3b17b4/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.williballenthin.com/registry/
COMMENT=	Read access to Windows Registry files
LICENSE=	apache-2.0

#DEPENDS+=	# TODO: enum-compat>=0
DEPENDS+=	${PYPKGPREFIX}-unicodecsv>=0.14.1:../../databases/py-unicodecsv

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
