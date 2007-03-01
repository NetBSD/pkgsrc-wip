# $NetBSD: Makefile,v 1.2 2007/03/01 19:12:15 shattered Exp $
#

DISTNAME=	ggz-client-libs-0.0.14
CATEGORIES=	wip
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14/

MAINTAINER=	mrohrer@users.sourceforge.net
HOMEPAGE=	http://www.ggzgamingzone.org
COMMENT=	GGZ Gaming Zone libraries

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-debug-gdb

.include "../../wip/ggz-libggz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
