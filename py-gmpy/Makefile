# $NetBSD: Makefile,v 1.2 2010/02/03 14:44:36 jihbed Exp $
#

DISTNAME=	gmpy-1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://gmpy.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/gmpy
COMMENT=	Library for arbitrary precision arithmetic wirtten by Python
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=	c c++


PYTHON_VERSIONS_INCOMPATIBLE= 23 22 21 20
PYDISTUTILSPKG= yes

INSTALLATION_DIRS=	share/doc/py-gmpy

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/gmpydoc.txt \
		${DESTDIR}${PREFIX}/share/doc/py-gmpy
	${INSTALL_DATA} ${WRKSRC}/doc/index.html \
		${DESTDIR}${PREFIX}/share/doc/py-gmpy

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
