# $NetBSD: Makefile,v 1.3 2012/01/30 02:23:22 noud4 Exp $
#

DISTNAME=	papy-1.0b1.tar
PKGNAME= ${PYPKGPREFIX}-${DISTNAME:S/.tar//}
PKGREVISION=	1
CATEGORIES=	parallel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/papy/
EXTRACT_SUFX=	.gz#md5=2cfa9ac9791eea16fdf8e3c34940e924

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/papy/
COMMENT=	Parallel Pipelines In Python
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-Pmw>=1.3.2:../../x11/py-Pmw
DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.2:../../devel/py-ctypes

WRKSRC=		${WRKDIR}/papy-1.0b1
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 27 26
PYDISTUTILSPKG=	yes

DOCDIR=	${PREFIX}/share/doc/py-papy

INSTALLATION_DIRS=	${DOCDIR}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test.py

post-install:
	cd ${WRKSRC}/doc/html && pax -rw -pp . ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
