# $NetBSD$

DISTNAME=	aioopenssl-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	https://files.pythonhosted.org/packages/b1/34/e28adb7600d8ccff787a841241bc2591a3661a66e4f171d38956c0cd3002/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/horazont/aioopenssl
COMMENT=	TLS-capable transport using OpenSSL for asyncio
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=19.1.0:../../security/py-OpenSSL

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
