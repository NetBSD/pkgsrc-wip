# $NetBSD: Makefile,v 1.8 2009/10/02 22:44:03 thomasklausner Exp $

DISTNAME=	ktorrent-${KTORRENT_VER}
CATEGORIES=	net kde
MASTER_SITES=	http://ktorrent.org/downloads/${KTORRENT_VER}/
EXTRACT_SUFX=	.tar.bz2

KTORRENT_VER=	3.1.3

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://ktorrent.org/
COMMENT=	Graphical BitTorrent client for KDE4

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		awk msgfmt pkg-config perl

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
