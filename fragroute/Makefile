# $NetBSD: Makefile,v 1.2 2004/01/25 02:12:12 grantbeattie Exp $
#

DISTNAME=	fragroute-1.2
CATEGORIES=	security
MASTER_SITES=	http://www.monkey.org/~dugsong/fragroute/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.monkey.org/~dugsong/fragroute/
COMMENT=	Intercept, modify and rewrite traffic

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

.include "../../devel/libevent/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../net/libdnet/buildlink2.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
