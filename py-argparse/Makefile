# $NetBSD: Makefile,v 1.1.1.1 2010/07/27 09:12:41 jihbed Exp $
#

DISTNAME=	argparse-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://argparse.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/argparse/
COMMENT=	Python command-line parsing library
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25 24
PYDISTUTILSPKG=	yes

do-test:
	${WRKSRC} && ${PYTHONBIN} test_argparse.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
