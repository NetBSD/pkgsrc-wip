# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=	pyttk-0.3.2
PKGNAME=	${PYPKGPREFIX}-ttk-0.3.2
CATEGORIES=	x11 python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyttk/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/python-ttk/
COMMENT=	Ttk Python wrapper
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/pyttk-0.3.2

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/test ; ${SETENV} ${TEST_ENV} ${PYTHONBIN} runtests.py

.include "../../x11/py-Tk/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
