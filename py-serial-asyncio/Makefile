# $NetBSD$

DISTNAME=	pyserial-asyncio-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyserial-asyncio/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pyserial/pyserial-asyncio
COMMENT=	Python Serial Port Extension, Asynchronous I/O support
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-serial>=3.4:../../comms/py-serial

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
