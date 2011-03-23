# $NetBSD: Makefile,v 1.1.1.1 2011/03/23 09:46:00 jihbed Exp $
#

DISTNAME=	swiginac-1.5.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://download.berlios.de/swiginac/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://swiginac.berlios.de/
COMMENT=	Interface to GiNaC, providing Python with symbolic mathematics
LICENSE=	cpl-1.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/tests/Symbolic; ${SETENV} ${TEST_ENV} ${PYTHONBIN} SymbolicTests.py
	${RUN} cd ${WRKSRC}/tests/swiginac; ${SETENV} ${TEST_ENV} ${PYTHONBIN} checkall.py

.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../wip/libginac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
