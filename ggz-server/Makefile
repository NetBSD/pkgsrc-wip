# $NetBSD: Makefile,v 1.1.1.1 2007/03/05 15:36:07 mrohrer Exp $
#

DISTNAME=	ggz-server-0.0.14
CATEGORIES=	wip
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14/

MAINTAINER=	mrohrer@users.sourceforge.net
HOMEPAGE=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14/
COMMENT=	GGZ Gaming Zone - Server package

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+= --enable-debug-gdb

.include "../../wip/ggz-libggz/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
