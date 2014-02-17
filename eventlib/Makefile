# $NetBSD: Makefile,v 1.8 2014/02/17 00:43:02 othyro Exp $
#

DISTNAME=	eventlib-0.1.5
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/e/eventlib/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://travis-ci.org/Yipit/eventlib/
COMMENT=	Asynchronous event tracking app for Django
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-ejson>=0.1.3:../../textproc/py-ejson
DEPENDS+=	${PYPKGPREFIX}-logan>=0.5.0:../../devel/py-logan
DEPENDS+=	celery>=3.0.9:../../wip/celery
DEPENDS+=	${PYPKGPREFIX}-redis-py>=2.7.1:../../databases/py-redis-py
DEPENDS+=	${PYPKGPREFIX}-django>=1.4.1:../../www/py-django
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
