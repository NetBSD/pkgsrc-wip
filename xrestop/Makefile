# $NetBSD: Makefile,v 1.2 2005/04/11 21:16:34 tvierling Exp $
#

DISTNAME=		xrestop-0.2
CATEGORIES=		x11
MASTER_SITES=		http://www.freedesktop.org/Software/xrestop/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.freedesktop.org/Software/xrestop
COMMENT=		X11 clients' server-side resource usage statistics

USE_X11=		yes
GNU_CONFIGURE=		yes

# or do we use ../../mk/curses.buildlink3.mk ??
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
