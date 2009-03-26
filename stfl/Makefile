# $NetBSD: Makefile,v 1.1.1.1 2009/03/26 15:55:22 smoppy Exp $
#

DISTNAME=	stfl-0.19
CATEGORIES=	devel
MASTER_SITES=	http://www.clifford.at/stfl/

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://www.clifford.at/stfl/
COMMENT=	Library which implements a curses-based widget set for text terminals

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake perl

PKG_DESTDIR_SUPPORT=	user-destdir

#
# TODO
#
# 	. Remove Makefile:76 wrong include
#

do-install:
	${INSTALL_LIB} ${WRKSRC}/libstfl.a ${DESTDIR}/${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/stfl.h ${DESTDIR}/${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
