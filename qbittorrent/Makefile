# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:07 noud4 Exp $

DISTNAME=	qbittorrent-3.1.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qbittorrent/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://www.qbittorrent.org/
COMMENT=	P2P Bittorrent client
LICENSE=	gnu-gpl-v2

DEPENDS+=	libtorrent-rasterbar>=0.15.0:../../wip/libtorrent-rasterbar

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	--qtdir=${PREFIX}/qt4
CONFIGURE_ARGS+=	--with-libboost-inc=${PREFIX}/include
CONFIGURE_ARGS+=	--with-libboost-lib=${PREFIX}/lib

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c++
INSTALLATION_DIRS+=	bin

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	configure
SUBST_VARS.paths=	PREFIX
SUBST_MESSAGE.paths=	Fixing paths.

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../net/GeoIP/buildlink3.mk"	# TODO optional

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../wip/libtorrent-rasterbar/buildlink3.mk"

.include "../../x11/qt4-qdbus/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
