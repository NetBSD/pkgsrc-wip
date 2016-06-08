# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:26 asau Exp $
#

DISTNAME=	pmi-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pmi/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://github.com/olenz/pmi/
COMMENT=	Parallel Method Invocation
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/pmi-1.0
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test_pmi.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
