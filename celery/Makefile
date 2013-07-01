# $NetBSD: Makefile,v 1.6 2013/07/01 02:23:48 othyro Exp $
#

DISTNAME=	celery-3.0.20
CATEGORIES=	net
MASTER_SITES=	http://pypi.python.org/packages/source/c/celery/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.celeryproject.org/
COMMENT=	Asynchronous task/job queue based on distributed message passing
LICENSE=	modified-bsd # AND cc-by-nc-sa-v3.0

USE_LANGUAGES=	c

DEPENDS+=	${PYPKGPREFIX}-anyjson-[0-9]*:../../wip/py-anyjson
DEPENDS+=	${PYPKGPREFIX}-billiard-[0-9]*:../../wip/py-billiard
DEPENDS+=	${PYPKGPREFIX}-kombu-[0-9]*:../../wip/py-kombu
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
