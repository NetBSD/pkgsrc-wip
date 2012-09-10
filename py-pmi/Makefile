# $NetBSD: Makefile,v 1.2 2012/09/10 09:34:47 jihbed Exp $
#

DISTNAME=	pmi-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pmi/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://github.com/olenz/pmi/
COMMENT=	Parallel Method Invocation
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pmi-1.0
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test_pmi.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
