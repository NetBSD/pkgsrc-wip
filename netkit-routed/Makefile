# $NetBSD: Makefile,v 1.5 2005/12/05 22:27:46 rillig Exp $
#

DISTNAME=		netkit-routed-0.17
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/ \
			${MASTER_SITE_SUNSITE:=system/network/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.hcs.harvard.edu/~dholland/computers/netkit.html
COMMENT=		Network RIP and router discovery daemon for Linux

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=--prefix=${PREFIX:Q}

.include "../../mk/bsd.pkg.mk"
