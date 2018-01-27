# $NetBSD$

DISTNAME=	Keras-1.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=k/keras/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/fchollet/keras
COMMENT=	Deep Learning for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
