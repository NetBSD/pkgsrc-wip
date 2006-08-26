# $NetBSD: Makefile,v 1.14 2006/08/26 14:35:26 airhead Exp $
#

DISTNAME=	mutella-0.4.5
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mutella/}

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://mutella.sourceforge.net/
COMMENT=	Console mode Gnutella client with optional HTTP interface

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PTHREAD_OPTS+=		require

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib.buildlink3.mk""
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
