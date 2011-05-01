# $NetBSD: Makefile,v 1.2 2011/05/01 02:57:50 genolopolis Exp $
#

DISTNAME=	kyotocabinet-1.2.52
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
