# $NetBSD: Makefile,v 1.1.1.1 2004/08/02 23:05:47 poppnk Exp $
#

DISTNAME=		netkit-routed-0.17
CATEGORIES=		wip net
MASTER_SITES=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/ \
			${MASTER_SITE_SUNSITE:=system/network/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.hcs.harvard.edu/~dholland/computers/netkit.html
COMMENT=		Network RIP and router discovery daemon for Linux

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

CONFIGURE_ARGS+=--prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
