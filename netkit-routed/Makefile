# $NetBSD: Makefile,v 1.7 2012/10/03 18:15:32 asau Exp $
#

DISTNAME=		netkit-routed-0.17
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/ \
			${MASTER_SITE_SUNSITE:=system/network/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.hcs.harvard.edu/~dholland/computers/netkit.html
COMMENT=		Network RIP and router discovery daemon for Linux

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
ONLY_FOR_PLATFORM=	Linux-*-*

CONFIGURE_ARGS+=--prefix=${PREFIX:Q}

.include "../../mk/bsd.pkg.mk"
