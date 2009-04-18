# $NetBSD: Makefile,v 1.1.1.1 2009/04/18 23:31:08 jihbed Exp $
#

DISTNAME=	pycsp-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel
MASTER_SITES=	http://pycsp.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/pycsp/
COMMENT=	PyCSP Python CSP Library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

EDGDIR=	${PREFIX}/share/example/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EDGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py \
		${DESTDIR}${EDGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
