# $NetBSD: Makefile,v 1.12 2012/01/22 13:21:47 airhead Exp $

MAJOR=		0
MINOR=		22
DISTNAME=	stfl-${MAJOR}.${MINOR}
CATEGORIES=	devel
MASTER_SITES=	http://www.clifford.at/stfl/

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://www.clifford.at/stfl/
COMMENT=	Library which implements a curses-based widget set for text terminals
LICENSE=	gnu-gpl-v3

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
SUBST_SED.makefile=	-e "s|LDLIBS.*|& -liconv -Wl,-R${PREFIX}/lib|"

PLIST_SUBST+=	MAJOR=${MAJOR:Q} MINOR=${MINOR:Q}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
