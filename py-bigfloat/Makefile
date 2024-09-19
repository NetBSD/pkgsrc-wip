# $NetBSD: Makefile,v 1.5 2012/10/06 17:22:16 asau Exp $
#

DISTNAME=	bigfloat-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bigfloat/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/b/bigfloat/
COMMENT=	Arbitrary precision correctly-rounded floating point arithmetic
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

WRKSRC=		${WRKDIR}/bigfloat-0.2.1
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/bigfloat; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test_bigfloat.py

.include "../../lang/python/extension.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
