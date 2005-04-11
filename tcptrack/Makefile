# $NetBSD: Makefile,v 1.2 2005/04/11 21:16:00 tvierling Exp $
#

DISTNAME=		tcptrack-1.1.4
CATEGORIES=		wip
MASTER_SITES=		http://www.rhythm.cx/~steve/devel/tcptrack/release/1.1.4/source/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.rhythm.cx/~steve/devel/tcptrack/
COMMENT=		Watch TCP connections

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
