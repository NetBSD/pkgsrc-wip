# $NetBSD$

DISTNAME=	python3-openid-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python3-//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python3-openid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/necaris/python3-openid/
COMMENT=	Python 3 port of the python2-openid library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
