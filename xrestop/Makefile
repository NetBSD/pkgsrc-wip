# $NetBSD: Makefile,v 1.3 2005/05/04 01:23:01 jeremy-c-reed Exp $
#

DISTNAME=		xrestop-0.3
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
