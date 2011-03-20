# $NetBSD: Makefile,v 1.1.1.1 2011/03/20 23:38:15 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} rpncalc_test.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
