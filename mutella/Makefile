# $NetBSD: Makefile,v 1.12 2005/04/12 21:53:57 airhead Exp $
#

DISTNAME=	mutella-0.4.5
CATEGORIES=	wip net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mutella/}

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://mutella.sourceforge.net/
COMMENT=	Console mode Gnutella client with optional HTTP interface

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
#
# XXX: This should be removed when PR lib/29958 is closed.  Not sure how to
#       check for native readline version with/without support though.
#
USE_GNU_READLINE=	yes

PTHREAD_OPTS+=		require

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
