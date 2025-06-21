# $NetBSD$

DISTNAME=	duc-1.4.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=zevv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://duc.zevv.nl/
COMMENT=	Collection of tools for inspecting and visualizing disk usage
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	autoconf automake autoreconf pkg-config
GNU_CONFIGURE=	yes

# Needed for checking for tputs in -lncursesw check
FAKE_NCURSES=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fi

.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
