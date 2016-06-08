# $NetBSD: Makefile,v 1.8 2014/01/18 19:56:17 thomasklausner Exp $

DISTNAME=	papy-1.0b1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	parallel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/papy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/papy/
COMMENT=	Parallel Pipelines In Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

PYTHON_VERSIONED_DEPENDENCIES=	Pmw

USE_TOOLS+=	pax
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

DOCDIR=	${PREFIX}/share/doc/py-papy

INSTALLATION_DIRS=	${DOCDIR}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test.py

post-install:
	cd ${WRKSRC}/doc/html && pax -rw -pp . ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
