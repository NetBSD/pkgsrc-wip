# $NetBSD: Makefile,v 1.2 2012/10/06 17:13:24 asau Exp $
#

DISTNAME=	EMpy-0.1.2.linux-i686
PKGNAME=	${PYPKGPREFIX}-EMpy-${VERSION}
CATEGORIES=	science python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/empy/EMpy/0.1.2/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://empy.sourceforge.net/
COMMENT=	Suite of numerical algorithms widely used in electromagnetism
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/usr

VERSION= 0.1.2
USE_TOOLS+=	pax
NO_BUILD=	yes
USE_LANGUAGES=	# none
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX:Q}
PY_PATCHPLIST=		yes

INSTALLATION_DIRS=	${PYSITELIB}

do-test:
	${PYTHONBIN} ${WRKSRC}/usr/lib/python2.6/site-packages/EMpy/ -c "import EMpy; EMpy.test()"

do-install:
	cd ${WRKSRC}/lib/python2.6/site-packages/EMpy && pax -rw -pp . ${DESTDIR}${PREFIX}/${PYSITELIB}/EMpy

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
