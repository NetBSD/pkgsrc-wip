# $NetBSD: Makefile,v 1.1.1.1 2003/04/12 12:36:50 virtus Exp $

DISTNAME=       qinx-0.3
CATEGORIES=	wm kde
MASTER_SITES=   http://www.usermode.org/code/

MAINTAINER=     flynn@energyhq.homeip.net
HOMEPAGE=	http://www.usermode.org/code.html
COMMENT=	Widget style and window decoration for KDE3

.include "../../x11/kde3/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"

PTHREAD_OPTS+=		require
USE_GMAKE=              YES
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
USE_BUILDLINK_ONLY=     YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS+=                  -Wl,--export-dynamic
.endif

.include "../../mk/bsd.pkg.mk"
