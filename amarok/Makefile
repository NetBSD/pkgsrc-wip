# $NetBSD: Makefile,v 1.6 2008/08/12 12:09:03 thomasklausner Exp $
#

# XXX: non-official, checkout from SVN post 1.86
DISTNAME=	amarok-1.87
CATEGORIES=	audio multimedia
#MASTER_SITES=	ftp://gd.tuwien.ac.at/kde/unstable/amarok/1.86/src/
MASTER_SITES=	${MASTER_SITE_LOCAL}
# XXX:
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://amarok.kde.org/en/node/529
COMMENT=	KDE audio player

BUILD_DEPENDS+=	automoc4>=0.9.83:../../wip/automoc4

#XXX: for SVN
WRKSRC=		${WRKDIR}/amarok

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
#CMAKE_ARG_PATH=	..

.include "options.mk"

.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../wip/kdemultimedia4/buildlink3.mk"
# for plasma
.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../wip/strigi/buildlink3.mk"
BUILDLINK_API_DEPENDS.taglib+=	taglib>=1.5
.include "../../audio/taglib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
