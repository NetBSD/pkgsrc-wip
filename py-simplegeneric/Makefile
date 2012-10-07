# $NetBSD: Makefile,v 1.5 2012/10/07 13:57:30 asau Exp $
#

DISTNAME=	simplegeneric-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/s/simplegeneric/
EXTRACT_SUFX=	.zip#md5=eaa358a5f9517a8b475d03fbee3ec90f

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://cheeseshop.python.org/pypi/simplegeneric
COMMENT=	Simple generic functions for Python
LICENSE=	zpl

USE_LANGUAGES=	# none

EGG_INFODIR= ${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

post-install:
	${CHMOD} -R og-w ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
