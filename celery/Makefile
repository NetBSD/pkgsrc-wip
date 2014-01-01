# $NetBSD: Makefile,v 1.11 2014/01/01 02:24:44 othyro Exp $
#

DISTNAME=	celery-3.1.7
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/c/celery/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.celeryproject.org/
COMMENT=	Asynchronous task/job queue based on distributed message passing
LICENSE=	modified-bsd # AND cc-by-nc-sa-v3.0

USE_LANGUAGES=	c

DEPENDS+=	${PYPKGPREFIX}-anyjson-[0-9]*:../../textproc/py-anyjson
DEPENDS+=	${PYPKGPREFIX}-billiard>=3.3.0.13:../../parallel/py-billiard
DEPENDS+=	${PYPKGPREFIX}-kombu>=3.0.8:../../net/py-kombu
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
