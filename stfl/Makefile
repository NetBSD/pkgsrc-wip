# $NetBSD: Makefile,v 1.2 2009/03/26 21:31:27 smoppy Exp $
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

INSTALL_MAKE_FLAGS+=    prefix=${PREFIX}
INSTALL_MAKE_FLAGS+=    DESTDIR=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
