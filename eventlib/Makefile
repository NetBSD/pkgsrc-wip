# $NetBSD: Makefile,v 1.3 2013/07/01 02:27:16 othyro Exp $
#

DISTNAME=	eventlib-0.1.2
CATEGORIES=	net
MASTER_SITES=	http://pypi.python.org/packages/source/e/eventlib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://travis-ci.org/Yipit/eventlib/
COMMENT=	Asynchronous event tracking app for Django
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-ejson>=0.1.3:../../wip/py-ejson
DEPENDS+=	${PYPKGPREFIX}-logan>=0.5.0:../../wip/py-logan
DEPENDS+=	celery>=3.0.9:../../wip/celery
DEPENDS+=	${PYPKGPREFIX}-redis-py>=2.7.1:../../wip/py-redis-py
DEPENDS+=	${PYPKGPREFIX}-django>=1.4.1:../../www/py-django
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
