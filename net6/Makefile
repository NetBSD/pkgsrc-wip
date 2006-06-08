# $NetBSD: Makefile,v 1.4 2006/06/08 11:14:27 absd Exp $
#

DISTNAME=		net6-1.2.2
CATEGORIES=		devel net
MASTER_SITES=		http://releases.0x539.de/net6/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://releases.0x539.de/net6/
COMMENT=		TCP protocol abstraction library for C++

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/net6-1.2.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c++

.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
