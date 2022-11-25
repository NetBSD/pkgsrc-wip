# $NetBSD$

DISTNAME=	pdf2image-1.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pdf2image/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Belval/pdf2image
COMMENT=	Command line tools to convert PDF to a PIL Image list
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.3.0:../../graphics/py-Pillow

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
