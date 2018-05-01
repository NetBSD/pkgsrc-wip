# $NetBSD: Makefile,v 1.3 2015/04/09 11:42:14 thomasklausner Exp $

DISTNAME=	workerpool-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://workerpool.googlecode.com/files/
LICENSE=	mit

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
