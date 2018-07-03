# $NetBSD: Makefile,v 1.7 2015/01/10 20:22:03 thomasklausner Exp $

DISTNAME=	shedskin-0.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/shedskin/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/shedskin/
COMMENT=	Python-to-c++ compiler
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.9.4

post-extract:
	cd ${WRKSRC}/scripts && ${MV} shedskin shedskin${PYVERSSUFFIX}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
