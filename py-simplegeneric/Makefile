# $NetBSD: Makefile,v 1.2 2010/08/29 10:32:49 jihbed Exp $
#

DISTNAME=	simplegeneric-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/s/simplegeneric/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/simplegeneric
COMMENT= Simple generic functions (similar to Python's own len(),pickle.dump())
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

EGG_INFODIR= ${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
post-install:
	${CHMOD} -R og-w ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
