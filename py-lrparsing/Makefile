# $NetBSD: Makefile,v 1.1 2015/08/05 20:51:57 jihbed Exp $

DISTNAME=	lrparsing-1.0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lrparsing/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://lrparsing.sourceforge.net/
COMMENT=	LR(1) parser hiding behind a pythonic interface
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/lrparsing; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
