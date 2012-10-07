# $NetBSD: Makefile,v 1.4 2012/10/07 13:57:30 asau Exp $
#

DISTNAME=	shedskin-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	http://shedskin.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/shedskin/
COMMENT=	Python-to-c++ compiler
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++

PYDISTUTILSPKG=yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	cd ${WRKSRC}/scripts && ${MV} shedskin shedskin${PYVERSSUFFIX}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
