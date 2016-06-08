# $NetBSD: Makefile,v 1.4 2013/06/04 07:45:24 thomasklausner Exp $

DISTNAME=	pyttk-0.3.2
PKGNAME=	${PYPKGPREFIX}-ttk-0.3.2
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyttk/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/python-ttk/
COMMENT=	Ttk Python wrapper
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

WRKSRC=		${WRKDIR}/pyttk-0.3.2

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/test ; ${SETENV} ${TEST_ENV} ${PYTHONBIN} runtests.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
