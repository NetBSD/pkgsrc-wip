# $NetBSD: Makefile,v 1.2 2005/09/11 04:31:01 udontknow Exp $
#

DISTNAME=		net6-1.1.0
CATEGORIES=		devel net
MASTER_SITES=		http://releases.0x539.de/net6/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://0x539.de/
COMMENT=		TCP protocol abstraction library for C++

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/net6-1.1.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
