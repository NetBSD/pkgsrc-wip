# $NetBSD: Makefile,v 1.1.1.1 2004/11/02 19:44:52 poppnk Exp $
#

DISTNAME=		tcptrack-1.1.4
CATEGORIES=		wip
MASTER_SITES=		http://www.rhythm.cx/~steve/devel/tcptrack/release/1.1.4/source/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.rhythm.cx/~steve/devel/tcptrack/
COMMENT=		Watch TCP connections

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
