# $NetBSD: Makefile,v 1.7 2004/08/17 18:32:07 tvierling Exp $
#

DISTNAME=	qinx-0.3
CATEGORIES=	wm kde
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	flynn@energyhq.homeip.net
HOMEPAGE=	http://www.usermode.org/code.html
COMMENT=	Widget style and window decoration for KDE3

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
LIBTOOL_LA_FILES+=	lib/kde3/kwin_qinx.la
LIBTOOL_LA_FILES+=	lib/kde3/kwin_qinx_config.la
LIBTOOL_LA_FILES+=	lib/kde3/plugins/styles/qinx.la
USE_GNU_TOOLS+=		make
USE_X11=		YES

LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
