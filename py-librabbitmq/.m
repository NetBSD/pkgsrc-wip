# $NetBSD: .m,v 1.1 2014/09/22 01:33:50 othyro Exp $

DISTNAME=	librabbitmq-1.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	https://pypi.python.org/packages/source/l/librabbitmq/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/celery/librabbitmq
COMMENT=	AMQP Client using the rabbitmq-c library
#LICENSE=	mpl-X

.include "../../lang/python/egg.mk"
.include "../../net/rabbitmq-c/buildlink3.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
