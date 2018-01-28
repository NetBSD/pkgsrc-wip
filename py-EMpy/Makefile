# $NetBSD: Makefile,v 1.4 2012/11/14 00:16:12 othyro Exp $
#

DISTNAME=	EMpy-0.1.2.linux-i686
PKGNAME=	${PYPKGPREFIX}-EMpy-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=empy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://empy.sourceforge.net/
COMMENT=	Suite of numerical algorithms widely used in electromagnetism
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/usr

VERSION=	0.1.2
USE_TOOLS+=	pax
NO_BUILD=	yes
USE_LANGUAGES=	# none
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PY_PATCHPLIST=	yes

INSTALLATION_DIRS=	${PYSITELIB}

do-test:
	${PYTHONBIN} ${WRKSRC}/usr/lib/python2.6/site-packages/EMpy/ -c "import EMpy; EMpy.test()"

do-install:
	cd ${WRKSRC}/lib/python2.6/site-packages/EMpy && pax -rw -pp . ${DESTDIR}${PREFIX}/${PYSITELIB}/EMpy

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
