# $NetBSD$

DISTNAME=	pydocstyle-5.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/a9/77/1d835e40656d361bf8bd0add08d2c39dc257fb66ef8e29fe357c33826d5f/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/PyCQA/pydocstyle/
COMMENT=	Python docstring style checker
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-snowballstemmer>=2.0.0:../../textproc/py-snowballstemmer

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
