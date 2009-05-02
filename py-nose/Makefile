# $NetBSD: Makefile,v 1.1.1.1 2009/05/02 00:05:32 jihbed Exp $
#

DISTNAME=	nose-0.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://python-nose.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/python-nose/
COMMENT=	Unittest-based testing framework for python
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

DOCDIR=	${PREFIX}/share/doc/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${DOCDIR}


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
