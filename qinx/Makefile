# $NetBSD: Makefile,v 1.4 2004/01/25 02:33:21 grantbeattie Exp $
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
USE_GNU_TOOLS+=		make
USE_X11=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
