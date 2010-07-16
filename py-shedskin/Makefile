# $NetBSD: Makefile,v 1.1.1.1 2010/07/16 22:35:17 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

PYTHON_VERSIONS_ACCEPTED= 26 25
PYDISTUTILSPKG=yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	cd ${WRKSRC}/scripts && ${MV} shedskin shedskin${PYVERSSUFFIX}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
