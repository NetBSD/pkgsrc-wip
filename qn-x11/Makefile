# $NetBSD: Makefile,v 1.3 2004/02/09 02:04:46 blef Exp $

DISTNAME=	qnx11__-1.2.x
PKGNAME=	qn-x11-0.1
WRKSRC= 	${WRKDIR}/gtk-qn-x11-theme-0.1
CATEGORIES=	x11
MASTER_SITES=	http://download.freshmeat.net/themes/qnx11__/

MAINTAINER=	flynn@energyhq.homeip.net
HOMEPAGE=	http://themes.freshmeat.net/projects/qnx11__/?topic_id=923%2C954
COMMENT=	GTK theme-engine to yield a QNX look and feel

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
