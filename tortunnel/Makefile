# $NetBSD: Makefile,v 1.2 2012/07/02 13:38:09 moubctez Exp $
#

DISTNAME=	tortunnel-0.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.thoughtcrime.org/software/tortunnel/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.thoughtcrime.org/software/tortunnel/
COMMENT=	Partial onion proxy for single-hop circuits through TOR
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
