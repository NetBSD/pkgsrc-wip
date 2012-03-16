# $NetBSD: Makefile,v 1.5 2012/03/16 00:23:23 bubuchka Exp $
#

DISTNAME=	kyotocabinet-1.2.73
CATEGORIES=	databases
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

# The TC seem very tight to 64-bit machines;
# the listed platforms are known as suffering from that
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MDarwin-*-i386)
CONFIGURE_ARGS+=	--disable-opt
.endif

PKGCONFIG_OVERRIDE+=	kyotocabinet.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
