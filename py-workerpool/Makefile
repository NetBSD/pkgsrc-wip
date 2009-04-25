# $NetBSD: Makefile,v 1.1.1.1 2009/04/25 23:07:27 jihbed Exp $
#

DISTNAME=	workerpool-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://workerpool.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/workerpool/
COMMENT=	Python multithreaded job distribution module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

EDGDIR=	${PREFIX}/share/example/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EDGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.py \
		${DESTDIR}${EDGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
