# $NetBSD$

DISTNAME=	le-1.16.5
CATEGORIES=	editors
MASTER_SITES=	http://lav.yar.ru/download/le/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lav.yar.ru/programs.html
COMMENT=	Full screen text editor inspired by Norton Editor
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
