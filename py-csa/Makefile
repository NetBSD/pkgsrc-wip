# $NetBSD: Makefile,v 1.1.1.1 2011/03/20 22:25:47 jihbed Exp $
#

DISTNAME=	csa-0.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math  python
MASTER_SITES=	http://pypi.python.org/packages/source/c/csa/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://software.incf.org/software/csa/
COMMENT=	The Connection-Set Algebra implemented in Python
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/csa-0.0.1

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_csa.py

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
