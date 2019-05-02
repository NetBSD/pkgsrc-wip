# $NetBSD$

DISTNAME=	trader-7.12
CATEGORIES=	games
MASTER_SITES=	https://ftp.zap.org.au/pub/trader/unix/

MAINTAINER=	fred@statdns.com
HOMEPAGE=	https://www.zap.org.au/software/trader/
COMMENT=	Simple text-based game of interstellar trading
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
