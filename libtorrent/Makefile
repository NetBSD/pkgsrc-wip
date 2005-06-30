# $NetBSD: Makefile,v 1.5 2005/06/30 11:27:17 imilh Exp $

DISTNAME=	libtorrent-0.6.6
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://libtorrent.rakshasa.no/
COMMENT=	BitTorrent library written in C++ for *nix

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

PREFER_PKGSRC=		openssl

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
