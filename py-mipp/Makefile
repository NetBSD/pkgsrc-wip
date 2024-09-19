# $NetBSD: Makefile,v 1.1 2014/06/20 09:33:49 jihbed Exp $

DISTNAME=	mipp-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mipp/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/loerum/mipp
COMMENT=	Meteorological ingest processing package
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testit

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
