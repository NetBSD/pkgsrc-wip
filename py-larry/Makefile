# $NetBSD: Makefile,v 1.2 2012/10/07 12:25:13 asau Exp $
#

DISTNAME=	la-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/la/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://larry.sourceforge.net/
COMMENT=	Label the rows, columns, any dimension, of your NumPy arrays
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/la-0.4.0
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/la/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} all_nan_test.py

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
