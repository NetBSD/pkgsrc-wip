# $NetBSD: Makefile,v 1.1.1.1 2010/05/16 15:52:28 jihbed Exp $
#

DISTNAME=	pmi-1.0.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	parallel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pmi/
EXTRACT_SUFX=	.gz#md5=5143b2e7ac718990c1c34ea9f095e335

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.espresso-pp.de/projects/pmi/
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
