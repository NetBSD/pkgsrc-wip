# $NetBSD: Makefile,v 1.6 2009/09/17 11:57:10 fjaeckel Exp $

DISTNAME=	bird-1.1.3
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/

MAINTAINER=	fjaeckel@jc-ix.net
HOMEPAGE=	http://bird.network.cz/
COMMENT= The BIRD Internet Routing Daemon

USE_LIBTOOL= yes
GNU_CONFIGURE= yes
USE_TOOLS+= gmake
USE_GNU_READLINE=  yes

PKG_DESTDIR_SUPPORT=  user-destdir

CONFIGURE_ARGS+= --localstatedir=/var

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/bison/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
