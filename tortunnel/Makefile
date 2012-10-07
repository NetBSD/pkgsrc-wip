# $NetBSD: Makefile,v 1.3 2012/10/07 17:17:45 asau Exp $
#

DISTNAME=	tortunnel-0.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.thoughtcrime.org/software/tortunnel/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.thoughtcrime.org/software/tortunnel/
COMMENT=	Partial onion proxy for single-hop circuits through TOR
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
