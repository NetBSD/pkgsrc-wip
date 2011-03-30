# $NetBSD: Makefile,v 1.8 2011/03/30 10:30:18 moubctez Exp $

DISTNAME=	tcptrack-1.4.0
CATEGORIES=	net
MASTER_SITES=	http://www.rhythm.cx/~steve/devel/tcptrack/release/${PKGVERSION_NOREV}/source/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.rhythm.cx/~steve/devel/tcptrack/
COMMENT=	Watch TCP connections
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
