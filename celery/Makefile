# $NetBSD: Makefile,v 1.4 2013/06/07 23:52:27 othyro Exp $
#

DISTNAME=	celery-3.0.19
CATEGORIES=	net
MASTER_SITES=	http://pypi.python.org/packages/source/c/celery/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.celeryproject.org/
COMMENT=	Asynchronous task/job queue based on distributed message passing
LICENSE=	modified-bsd # AND cc-by-nc-sa-v3.0

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-billiard-[0-9]*:../../wip/py-billiard
DEPENDS+=	${PYPKGPREFIX}-kombu-[0-9]*:../../wip/py-kombu
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
