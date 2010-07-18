# $NetBSD: Makefile,v 1.4 2010/07/18 21:50:12 jihbed Exp $
#

DISTNAME=	pp-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=	http://www.parallelpython.com/downloads/pp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.parallelpython.com/
COMMENT=	Parallel and distributed programming for Python
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
post-extract:
	cd ${WRKSRC} && ${MV} ppserver.py ppserver${PYVERSSUFFIX}

DOCDIR=	${PREFIX}/share/doc/py-pp
EGDIR=		${PREFIX}/share/examples/py-pp

MESSAGE_SUBST+=	DOCDIR=${DOCDIR}
MESSAGE_SUBST+=	EGDIR=${EGDIR}

INSTALLATION_DIRS=	${PKGMANDIR}/man1

USE_LANGUAGES=	# none

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/ppserver.1\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ppdoc.html\
			${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py\
			${DESTDIR}${EGDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
