# $NetBSD: Makefile,v 1.1.1.1 2009/04/24 22:59:25 jihbed Exp $
#

DISTNAME=	pp-1.5.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=	http://www.parallelpython.com/downloads/pp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.parallelpython.com/
COMMENT=	Parallel and distributed programming for Python

PKG_DESTDIR_SUPPORT=	user-destdir

DOCDIR=	${PREFIX}/share/doc/${PYPKGPREFIX}-pp-1.5.7
EGDIR=		${PREFIX}/share/examples/${PYPKGPREFIX}-pp-1.5.7

MESSAGE_SUBST+=	DOCDIR=${DOCDIR}
MESSAGE_SUBST+=	EGDIR=${EGDIR}

INSTALLATION_DIRS=	${PKGMANDIR}/man1

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

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
