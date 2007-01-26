# $NetBSD: Makefile,v 1.1.1.1 2007/01/26 17:16:04 mrohrer Exp $
#

DISTNAME=	ggz-gtk-games-0.0.14
CATEGORIES=	wip
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14/

MAINTAINER=     mrohrer@users.sourceforge.net
HOMEPAGE=       http://www.ggzgamingzone.org
COMMENT=        GGZ Gaming Zone libraries

CONFIGURE_ARGS+= --enable-debug-gdb

GNU_CONFIGURE=	yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/ggz-client-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
