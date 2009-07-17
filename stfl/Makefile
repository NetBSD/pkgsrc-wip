# $NetBSD: Makefile,v 1.8 2009/07/17 20:35:54 smoppy Exp $

DISTNAME=	stfl-0.21
CATEGORIES=	devel
MASTER_SITES=	http://www.clifford.at/stfl/

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://www.clifford.at/stfl/
COMMENT=	Library which implements a curses-based widget set for text terminals

NO_INSTALL_MANPAGES=	yes
PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake perl iconv
USE_NCURSES=	yes
USE_GNU_ICONV=	yes

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}

# Makefile
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing distribution Makefile...
SUBST_FILES.makefile=	${MAKE_FILE}
SUBST_SED.makefile=	-e 's/LDLIBS.*/& -liconv/'

.include "../../mk/bsd.prefs.mk"

# NetBSD iconv implementation doesn't support
# the wchar_t encoding (upon stfl relies).
.if ${OPSYS} == "NetBSD"
.include "../../converters/libiconv/buildlink3.mk"
.endif

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
