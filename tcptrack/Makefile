# $NetBSD: Makefile,v 1.4 2006/06/14 09:14:48 absd Exp $
#

DISTNAME=		tcptrack-1.1.4
CATEGORIES=		net
MASTER_SITES=		http://www.rhythm.cx/~steve/devel/tcptrack/release/1.1.4/source/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.rhythm.cx/~steve/devel/tcptrack/
COMMENT=		Watch TCP connections

USE_LANGUAGES=		c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
