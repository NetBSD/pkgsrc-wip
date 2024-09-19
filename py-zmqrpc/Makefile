# $NetBSD$

DISTNAME=	pyzmqrpc-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	python net
MASTER_SITES=	https://files.pythonhosted.org/packages/91/fa/5cbea22a0a792bf29c35a5f2787f4425fa18cf77a57ed04b77cb4dc2282a/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jverhoeven/pyzmqrpc
COMMENT=	Simple ZMQ RPC extension with JSON for message serialization
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-zmq>=19.0.2:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-future>=0.15.0:../../devel/py-future

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
