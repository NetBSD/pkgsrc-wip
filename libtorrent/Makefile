# $NetBSD: Makefile,v 1.3 2005/06/08 12:08:29 poppnk Exp $

DISTNAME=	libtorrent-0.6.4
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://libtorrent.rakshasa.no/
COMMENT=	BitTorrent library written in C++ for *nix

USE_LIBTOOL=		yes
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

PREFER_PKGSRC=		openssl

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
