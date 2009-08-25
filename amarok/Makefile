# $NetBSD: Makefile,v 1.10 2009/08/25 16:26:46 thomasklausner Exp $
#

DISTNAME=	amarok-${VERS}
VERS=		2.1.1
CATEGORIES=	audio multimedia
MASTER_SITES=	http://download.kde.org/stable/amarok/${VERS}/src/ \
		ftp://gd.tuwien.ac.at/kde/stable/amarok/${VERS}/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://amarok.kde.org/
COMMENT=	KDE4 audio player

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

CMAKE_ARGS+=	-DMYSQL_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.mysql-embedded}/mysqld/include/mysql
CMAKE_ARGS+=	-DMYSQL_EMBEDDED_LIBRARIES:PATH=${BUILDLINK_PREFIX.mysql-embedded}/mysqld/lib/mysql/libmysqld.a
CMAKE_ARGS+=	-DMYSQL_EMBEDDED_FOUND:BOOL=TRUE
CMAKE_ARGS+=	-DHAVE_MYSQL_OPT_EMBEDDED_CONNECTION:BOOL=TRUE
CMAKE_ARGS+=	-DMYSQL_LIBRARIES:PATH=${BUILDLINK_PREFIX.mysql-client}/lib/mysql/libmysqlclient.so

SUBST_CLASSES+=		mysql
SUBST_STAGE.mysql=	post-patch
SUBST_MESSAGE.mysql=	Fixup paths for MySQL embedded
SUBST_FILES.mysql=	cmake/modules/FindMySQLAmarok.cmake
SUBST_SED.mysql=	-e s:/opt/mysqle/:${BUILDLINK_PREFIX.mysql-embedded}/mysqld:

# uses its own internal plasma library/includes but if system plasma not 
# there will install some plasma config.
# dont use buildlink as results in header file conflicts
#DEPENDS+=	kdebase-workspace4>=4.1.3:../../wip/kdebase-workspace4

.include "options.mk"

BUILDLINK_API_DEPENDS.taglib+=	taglib>=1.5
.include "../../audio/taglib/buildlink3.mk"
.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../wip/taglib-extras/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/mysql5-embedded/buildlink3.mk"
.include "../../wip/kdemultimedia4/buildlink3.mk"
# for plasma
.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/qtscriptgenerator/buildlink3.mk"
.include "../../wip/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
