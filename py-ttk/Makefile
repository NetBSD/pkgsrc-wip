# $NetBSD: Makefile,v 1.1.1.1 2012/01/17 13:29:56 jihbed Exp $
#

DISTNAME=	pyttk-0.3.2
PKGNAME=	${PYPKGPREFIX}-ttk-0.3.2
CATEGORIES=	x11 python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyttk/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/python-ttk/
COMMENT=	Ttk Python wrapper
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pyttk-0.3.2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 31 27 26 25
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/test ; ${SETENV} ${TEST_ENV} ${PYTHONBIN} runtests.py

.include "../../x11/py-Tk/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
