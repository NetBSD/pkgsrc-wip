# $NetBSD: Makefile,v 1.7 2008/08/25 12:23:45 thomasklausner Exp $
#

DISTNAME=	amarok-1.90
CATEGORIES=	audio multimedia
MASTER_SITES=	http://download.kde.org/unstable/amarok/1.90/src/ \
		ftp://gd.tuwien.ac.at/kde/unstable/amarok/1.90/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://amarok.kde.org/en/releases/2.0/beta/1
COMMENT=	KDE4 audio player

BUILD_DEPENDS+=	automoc4>=0.9.83:../../wip/automoc4

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "options.mk"

BUILDLINK_API_DEPENDS.taglib+=	taglib>=1.5
.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdemultimedia4/buildlink3.mk"
# for plasma
.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../wip/strigi/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
