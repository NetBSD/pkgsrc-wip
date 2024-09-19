# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:51 othyro Exp $
#

DISTNAME=	rpncalc-2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=calcrpnpy/}
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
