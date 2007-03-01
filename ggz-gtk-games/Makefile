# $NetBSD: Makefile,v 1.2 2007/03/01 19:12:16 shattered Exp $
#

DISTNAME=	ggz-gtk-games-0.0.14
CATEGORIES=	wip
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14/

MAINTAINER=	mrohrer@users.sourceforge.net
HOMEPAGE=	http://www.ggzgamingzone.org
COMMENT=	GGZ Gaming Zone libraries

CONFIGURE_ARGS+= --enable-debug-gdb

GNU_CONFIGURE=	yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/ggz-client-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
