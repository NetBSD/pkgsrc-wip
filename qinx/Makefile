# $NetBSD: Makefile,v 1.3 2003/07/31 08:14:09 marttikuparinen Exp $
#

DISTNAME=	qinx-0.3
CATEGORIES=	wm kde
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	flynn@energyhq.homeip.net
HOMEPAGE=	http://www.usermode.org/code.html
COMMENT=	Widget style and window decoration for KDE3

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
USE_X11=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
