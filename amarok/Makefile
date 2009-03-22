# $NetBSD: Makefile,v 1.9 2009/03/22 19:18:29 thomasklausner Exp $
#

DISTNAME=	amarok-${VERS}
VERS=		1.94
CATEGORIES=	audio multimedia
MASTER_SITES=	http://download.kde.org/unstable/amarok/${VERS}/src/ \
		ftp://gd.tuwien.ac.at/kde/unstable/amarok/${VERS}/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://amarok.kde.org/
COMMENT=	KDE4 audio player

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		mysql
SUBST_STAGE.mysql=	post-patch
SUBST_MESSAGE.mysql=	Fixup paths for MySQL embedded
SUBST_FILES.mysql=	cmake/modules/FindMySQLAmarok.cmake
SUBST_SED.mysql=	-e s:/opt/mysqle/:${BUILDLINK_PREFIX.mysql-embedded}/:

# uses its own internal plasma library/includes but if system plasma not 
# there will install some plasma config.
# dont use buildlink as results in header file conflicts
DEPENDS+=	kdebase-workspace4>=4.1.3:../../wip/kdebase-workspace4

.include "options.mk"

BUILDLINK_API_DEPENDS.taglib+=	taglib>=1.5
.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/mysql5-embedded/buildlink3.mk"
.include "../../wip/kdemultimedia4/buildlink3.mk"
# for plasma
#.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
