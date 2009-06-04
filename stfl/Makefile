# $NetBSD: Makefile,v 1.6 2009/06/04 09:36:42 smoppy Exp $

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
USE_NCURSES=	yes

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
