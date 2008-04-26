# $NetBSD: Makefile,v 1.3 2008/04/26 01:06:27 thomasklausner Exp $
#

DISTNAME=	ggz-gtk-client-0.0.14
CATEGORIES=	games
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14/

MAINTAINER=	mrohrer@users.sourceforge.net
HOMEPAGE=	http://www.ggzgamingzone.org
COMMENT=	GGZ Gaming Zone libraries

CONFIGURE_ARGS+= --enable-debug-gdb

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../games/ggz-client-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
