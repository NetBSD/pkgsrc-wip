# $NetBSD: Makefile,v 1.1.1.1 2010/09/02 12:20:27 jihbed Exp $
#

DISTNAME=	cclib-1.0.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	biology python
MASTER_SITES=	http://pypi.python.org/packages/source/c/cclib/
EXTRACT_SUFX=	.gz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cclib.sourceforge.net/wiki/index.php/Main_Page
COMMENT=	Parsers and algorithms for computational chemistry
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/cclib-1.0
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/src/scripts/ccget ${WRKSRC}/src/scripts/ccget${PYVERSSUFFIX}
	${MV} ${WRKSRC}/src/scripts/cda ${WRKSRC}/src/scripts/cda${PYVERSSUFFIX}

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/testall.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
