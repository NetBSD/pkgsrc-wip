# $NetBSD: Makefile,v 1.7 2013/06/04 07:45:23 thomasklausner Exp $

DISTNAME=	papy-1.0b1
PKGNAME= ${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	parallel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/papy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/papy/
COMMENT=	Parallel Pipelines In Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-Pmw>=1.3.2:../../x11/py-Pmw
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

WRKSRC=		${WRKDIR}/papy-1.0b1
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
.include "../../mk/bsd.pkg.mk"
