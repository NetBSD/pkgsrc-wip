# $NetBSD: Makefile,v 1.1.1.1 2009/07/16 17:36:29 jihbed Exp $
#

DISTNAME=	gmpy-1.04
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://gmpy.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/gmpy
COMMENT=	Library for arbitrary precision arithmetic wirtten by Python
#LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYDISTUTILSPKG= yes

INSTALLATION_DIRS=	share/doc/py-gmpy

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/gmpydoc.txt \
		${DESTDIR}${PREFIX}/share/doc/py-gmpy

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
