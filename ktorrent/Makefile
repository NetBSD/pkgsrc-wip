# $NetBSD: Makefile,v 1.2 2006/10/29 08:32:45 shattered Exp $

DISTNAME=	ktorrent-${KTORRENT_VER}
CATEGORIES=	net kde
MASTER_SITES=	http://ktorrent.pwsp.net/downloads/${KTORRENT_VER}/

KTORRENT_VER=	2.0rc1

MAINTAINER=	pkg-maintainer@NetBSD.org
HOMEPAGE=	http://ktorrent.org/
COMMENT=	Graphical BitTorrent client for KDE

USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
