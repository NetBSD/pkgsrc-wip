# $NetBSD: Makefile,v 1.2 2015/02/20 16:13:26 jihbed Exp $

DISTNAME=	txZMQ-0.7.3
PKGNAME=	${PYPKGPREFIX}-txZMQ-0.7.3
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/txZMQ/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/smira/txZMQ
COMMENT=	Twisted bindings for ZeroMQ
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-zmq>=14.4.1:../../net/py-zmq

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
