# $NetBSD: Makefile,v 1.1.1.1 2005/10/03 15:53:38 poppnk Exp $
#

DISTNAME=		kismet-2005-08-R1
CATEGORIES=		wip net
MASTER_SITES=		http://www.kismetwireless.net/code/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.kismetwireless.net/code/
COMMENT=		802.11 wireless network detector, sniffer and IDS.

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

USE_LANGUAGES+=		c c++
# On Debian I had to `ln -s /usr/lib/libstdc++.so.6 /usr/liblibstc++.so

pre-build:
	cd ${WRKSRC} && ${GMAKE} dep

ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-* OpenBSD-*-*
# NetBSD ?

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
