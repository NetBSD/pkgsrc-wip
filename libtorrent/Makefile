# $NetBSD: Makefile,v 1.1.1.1 2005/03/21 14:12:18 imilh Exp $

DISTNAME=	libtorrent-0.5.4
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://libtorrent.rakshasa.no/
COMMENT=	BitTorrent library written in C++ for *nix

USE_LIBTOOL=		yes
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

PREFER_PKGSRC=		openssl

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
