# $NetBSD: Makefile,v 1.1.1.1 2010/05/06 09:51:04 jihbed Exp $
#

DISTNAME=	sympycore-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://sympycore.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/sympycore/
COMMENT=	SympyCore an efficient pure Python Computer Algebra System
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

HTMLDIR=	${PREFIX}/share/doc/html/py-sympycore

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DESTDIR}${HTMLDIR}

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
