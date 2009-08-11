# $NetBSD: Makefile,v 1.10 2009/08/11 21:34:07 smoppy Exp $

DISTNAME=	stfl-0.21
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
USE_GNU_ICONV=	yes

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}

# Makefile
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing distribution Makefile...
SUBST_FILES.makefile=	${MAKE_FILE}
SUBST_SED.makefile=	-e 's/LDLIBS.*/& -liconv/'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
