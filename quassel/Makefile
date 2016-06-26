# $NetBSD$

DISTNAME=	quassel-0.12.4
CATEGORIES=	chat
MASTER_SITES=	http://quassel-irc.org/pub/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://quassel-irc.org/
COMMENT=	Modern, cross-platform, distributed IRC clint
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_TOOLS+=	bash perl
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

REPLACE_BASH+=	data/scripts/inxi
REPLACE_BASH+=	po/update.sh
REPLACE_BASH+=	scripts/tx-sync.sh

REPLACE_PERL+=	data/scripts/mpris

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/libdbusmenu-qt/buildlink3.mk"
.include "../../multimedia/phonon/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
