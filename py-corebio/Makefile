# $NetBSD: Makefile,v 1.1.1.1 2011/03/20 23:35:10 jihbed Exp $
#

DISTNAME=	CoreBio-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/C/c/S/B/b/}
CATEGORIES=	biology python
MASTER_SITES=	http://corebio.googlecode.com/svn/dist/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/corebio/
COMMENT=	Python toolkit for computational biology
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=  26 25 24 23
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} rununittests.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
