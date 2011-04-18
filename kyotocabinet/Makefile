# $NetBSD: Makefile,v 1.1.1.1 2011/04/18 11:12:35 genolopolis Exp $
#

DISTNAME=	kyotocabinet-1.2.51
CATEGORIES=	wip
MASTER_SITES=	http://fallabs.com/kyotocabinet/pkg/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://fallabs.com/kyotocabinet/
COMMENT=	Straightforward implementation of DBM
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	kyotocabinet.pc.in

.include "../../mk/bsd.pkg.mk"
