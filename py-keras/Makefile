# $NetBSD$

DISTNAME=	Keras-1.0.5
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/b5/54/a9481d688241399e4d672bb544552fa6c59e2f7ef445ae1d2344d1f52684/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/fchollet/keras
COMMENT=	Deep Learning for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
