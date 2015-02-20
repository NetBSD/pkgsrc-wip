# $NetBSD: Makefile,v 1.1 2015/02/20 10:38:34 jihbed Exp $

DISTNAME=	txZMQ-0.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	net python
MASTER_SITES=	https://pypi.python.org/packages/source/t/txZMQ/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/smira/txZMQ
COMMENT=	Twisted bindings for ZeroMQ
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-zmq>=14.4.1:../../net/py-zmq

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
