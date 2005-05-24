# $NetBSD: Makefile,v 1.3 2005/05/24 10:31:13 rillig Exp $
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
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=--prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
