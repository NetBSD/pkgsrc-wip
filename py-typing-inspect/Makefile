# $NetBSD$

DISTNAME=	typing_inspect-0.6.0
PKGNAME=	${PYPKGPREFIX}-typing-inspect-0.6.0
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/84/06/8610d429f5d8d6e145abd0ac6a1a6a120c5f6fcbe174d43ddde549b1c582/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ilevkivskyi/typing_inspect
COMMENT=	Runtime inspection utilities for typing module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=0.4.3:../../lang/py-mypy_extensions
#For Python2.7 !
#DEPENDS+=	${PYPKGPREFIX}-typing>=3.5.2.2:../../devel/py-typing
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
