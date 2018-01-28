# $NetBSD: Makefile,v 1.8 2012/11/25 23:32:28 othyro Exp $
#

DISTNAME=		netkit-routed-0.17
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/ \
			${MASTER_SITE_SUNSITE:=system/network/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hcs.harvard.edu/~dholland/computers/netkit.html
COMMENT=		Network RIP and router discovery daemon for Linux


USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
ONLY_FOR_PLATFORM=	Linux-*-*

CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
