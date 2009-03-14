# $NetBSD: Makefile,v 1.7 2009/03/14 20:28:54 jihbed Exp $
#

DISTNAME=	tcptrack-1.3.0
CATEGORIES=	net
MASTER_SITES=	http://www.rhythm.cx/~steve/devel/tcptrack/release/1.3.0/source/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.rhythm.cx/~steve/devel/tcptrack/
COMMENT=	Watch TCP connections

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
