# $NetBSD: Makefile,v 1.2 2012/01/30 04:41:24 noud4 Exp $
#

DISTNAME=	bigfloat-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/b/bigfloat/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/b/bigfloat/
COMMENT= Arbitrary precision correctly-rounded floating point arithmetic
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.2:../../devel/py-ctypes

WRKSRC=		${WRKDIR}/bigfloat-0.2.1
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/bigfloat; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test_bigfloat.py

.include "../../lang/python/extension.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
