# $NetBSD: Makefile,v 1.12 2007/01/14 20:11:47 shattered Exp $
#

DISTNAME=	qinx-1.4
CATEGORIES=	wm kde
MASTER_SITES=	http://www.usermode.org/code/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	flynn@energyhq.homeip.net
HOMEPAGE=	http://www.usermode.org/code.html
COMMENT=	Widget style and window decoration for KDE3

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

# LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
