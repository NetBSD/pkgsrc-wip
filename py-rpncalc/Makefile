# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	rpncalc-2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/calcrpnpy/rpncalc/rpncalc-2.7/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://calcrpnpy.sourceforge.net/
COMMENT=	RPN Calculator For Python
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} rpncalc_test.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
