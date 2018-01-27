# $NetBSD: Makefile,v 1.12 2012/10/07 14:53:42 asau Exp $

DISTNAME=	qnx11__-1.2.x
PKGNAME=	qn-x11-0.1
WRKSRC=		${WRKDIR}/gtk-qn-x11-theme-0.1
CATEGORIES=	x11
MASTER_SITES=	http://download.freshmeat.net/themes/qnx11__/

MAINTAINER=	flynn@energyhq.homeip.net
HOMEPAGE=	http://themes.freshmeat.net/projects/qnx11__/?topic_id=923%2C954
COMMENT=	GTK theme-engine to yield a QNX look and feel


GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
