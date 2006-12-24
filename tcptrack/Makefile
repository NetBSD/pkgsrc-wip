# $NetBSD: Makefile,v 1.6 2006/12/24 21:30:22 shattered Exp $
#

DISTNAME=		tcptrack-1.2.0
CATEGORIES=		net
MASTER_SITES=		http://www.rhythm.cx/~steve/devel/tcptrack/release/1.2.0/source/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.rhythm.cx/~steve/devel/tcptrack/
COMMENT=		Watch TCP connections

USE_LANGUAGES=		c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
