# $NetBSD: Makefile,v 1.4 2009/03/27 09:53:07 smoppy Exp $

DISTNAME=	stfl-0.19
CATEGORIES=	devel
MASTER_SITES=	http://www.clifford.at/stfl/

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://www.clifford.at/stfl/
COMMENT=	Library which implements a curses-based widget set for text terminals

NO_INSTALL_MANPAGES=	yes
PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake perl

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
