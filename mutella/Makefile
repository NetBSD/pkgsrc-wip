# $NetBSD: Makefile,v 1.9 2004/03/14 22:27:00 poppnk Exp $
#

DISTNAME=	mutella-0.4.3
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mutella/}

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://mutella.sourceforge.net
COMMENT=	Console mode Gnutella client with optional HTTP interface

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PTHREAD_OPTS+=		require

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
