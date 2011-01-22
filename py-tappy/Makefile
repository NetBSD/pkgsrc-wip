# $NetBSD: Makefile,v 1.1.1.1 2011/01/22 13:37:27 jihbed Exp $
#

DISTNAME=	tappy-0.8.3
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tappy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://tappy.sourceforge.net/
COMMENT=	Tidal analysis program in python
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/tappy.py  ${WRKSRC}/tappy${PYVERSSUFFIX}

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests/test_tappy.py

.include "../../devel/py-readline/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
