# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	workerpool-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://workerpool.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/workerpool/
COMMENT=	Python multithreaded job distribution module

USE_LANGUAGES=	# none

EDGDIR=	${PREFIX}/share/example/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EDGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.py \
		${DESTDIR}${EDGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
