# $NetBSD: Makefile,v 1.1 2015/04/09 15:09:55 angelmm1 Exp $

DISTNAME=	locustio-0.7.2
CATEGORIES=	local devel www
MASTER_SITES=	https://pypi.python.org/packages/source/l/locustio/

MAINTAINER=	angel.medinamoscat@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/locustio
COMMENT=	Python utility for doing distributed load testing of a web site
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	py27-gevent>=1.0.1:../../net/py-gevent
DEPENDS+=	py27-flask>=0.10.1:../../www/py-flask
DEPENDS+=	py27-requests>=2.4.1:../../devel/py-requests
DEPENDS+=	py27-msgpack>=0.4.2:../../devel/py-msgpack

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
