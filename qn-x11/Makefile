# $NetBSD: Makefile,v 1.1.1.1 2003/04/12 12:28:01 virtus Exp $

DISTNAME=		qnx11__-1.2.x
PKGNAME=		qn-x11-0.1
WRKSRC= 		${WRKDIR}/gtk-qn-x11-theme-0.1
CATEGORIES=		x11
MASTER_SITES=		http://download.freshmeat.net/themes/qnx11__/

MAINTAINER=		flynn@energyhq.homeip.net
HOMEPAGE=		http://themes.freshmeat.net/projects/qnx11__/?topic_id=923%2C954
COMMENT=		GTK theme-engine to yield a QNX look and feel

DEPENDS+=		gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=		# defined
USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
