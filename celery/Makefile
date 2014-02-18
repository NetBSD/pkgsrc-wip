# $NetBSD: Makefile,v 1.12 2014/02/18 03:19:46 othyro Exp $
#

DISTNAME=	celery-3.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/c/celery/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.celeryproject.org/
COMMENT=	Asynchronous task/job queue based on distributed message passing
LICENSE=	modified-bsd # AND cc-by-nc-sa-v3.0

DEPENDS+=	${PYPKGPREFIX}-anyjson-[0-9]*:../../textproc/py-anyjson
DEPENDS+=	${PYPKGPREFIX}-billiard>=3.3.0.14:../../parallel/py-billiard
DEPENDS+=	${PYPKGPREFIX}-kombu>=3.0.12:../../net/py-kombu
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	c

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/celery \
		${DESTDIR}${PREFIX}/bin/celery${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/celerybeat \
		${DESTDIR}${PREFIX}/bin/celerybeat${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/celeryd \
		${DESTDIR}${PREFIX}/bin/celeryd${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/celeryd-multi \
		${DESTDIR}${PREFIX}/bin/celeryd-multi${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
