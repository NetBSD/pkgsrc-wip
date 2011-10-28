# $NetBSD: Makefile,v 1.1.1.1 2011/10/28 20:22:15 jihbed Exp $
#

DISTNAME=	polymul-1.01
CATEGORIES=	math
MASTER_SITES=	http://polymul.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/polymul/
COMMENT=	Fast multivariate polynomial multiplication in C++
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD= yes
USE_LANGUAGES=	c++

REPLACE_PYTHON+=	gentab.py
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

INSTALLATION_DIRS= bin include share/doc/polymul

post-extract:
	${MV} ${WRKSRC}/gentab.py ${WRKSRC}/gentab${PYVERSSUFFIX}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gentab${PYVERSSUFFIX} ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/polymul.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/README  ${DESTDIR}${PREFIX}/share/doc/polymul

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
