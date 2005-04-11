# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:30 tvierling Exp $
#

DISTNAME=		netkit-routed-0.17
CATEGORIES=		wip net
MASTER_SITES=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/ \
			${MASTER_SITE_SUNSITE:=system/network/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.hcs.harvard.edu/~dholland/computers/netkit.html
COMMENT=		Network RIP and router discovery daemon for Linux

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

CONFIGURE_ARGS+=--prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
