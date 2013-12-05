# $NetBSD: Makefile,v 1.6 2013/12/05 12:00:37 jihbed Exp $

DISTNAME=	fuzzpy-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/f/fuzzpy/
EXTRACT_SUFX=	.tar.bz2
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/ezod/fuzzpy
COMMENT=	Fuzzy sets, graphs, and mathematics for Python
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

DEPENDS+=	epydoc>=2.1:../../devel/epydoc
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
