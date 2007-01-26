# $NetBSD: Makefile,v 1.1.1.1 2007/01/26 17:13:28 mrohrer Exp $
#

DISTNAME=	ggz-client-libs-0.0.14
CATEGORIES=	wip
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14/

MAINTAINER=     mrohrer@users.sourceforge.net
HOMEPAGE=       http://www.ggzgamingzone.org
COMMENT=        GGZ Gaming Zone libraries

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+= 	--enable-debug-gdb

.include "../../wip/ggz-libggz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
