# $NetBSD: Makefile,v 1.1.1.1 2004/03/20 01:25:51 jeremy-c-reed Exp $
#

DISTNAME=		xrestop-0.2
CATEGORIES=		x11
MASTER_SITES=		http://www.freedesktop.org/Software/xrestop/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.freedesktop.org/Software/xrestop
COMMENT=		X11 clients' server-side resource usage statistics

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

# or do we use ../../mk/curses.buildlink3.mk ??
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
