# $NetBSD: Makefile,v 1.4 2013/12/12 13:00:58 noud4 Exp $
#

DISTNAME=	tortunnel-0.3
CATEGORIES=	net
MASTER_SITES=	http://www.thoughtcrime.org/software/tortunnel/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.thoughtcrime.org/software/tortunnel/
COMMENT=	Partial onion proxy for single-hop circuits through TOR
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
