# $NetBSD: Makefile,v 1.3 2008/07/27 11:58:27 plunky Exp $
#

DISTNAME=	zyGrib-1.6.1
CATEGORIES=	geography
MASTER_SITES=	http://zygrib.free.fr/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	plunky@rya-online.net
HOMEPAGE=	http://zygrib.free.fr/
COMMENT=	GRIB file viewer for weather data

#LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/zyGrib
USE_LANGUAGES=	c c++
USE_TOOLS+=	make

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Fixing shared data paths.
SUBST_FILES.paths=	src/GisReader.cpp src/MenuBar.cpp
SUBST_FILES.paths+=	src/MainWindow.cpp src/main.cpp
SUBST_SED.paths+=	-e "s|maps/|${PREFIX}/share/zyGrib/maps/|"
SUBST_SED.paths+=	-e "s|img/|${PREFIX}/share/zyGrib/img/|"
SUBST_SED.paths+=	-e "s|tr/|${PREFIX}/share/zyGrib/tr/|"

INSTALLATION_DIRS+=	share/zyGrib/maps/gis share/zyGrib/maps/gshhs
INSTALLATION_DIRS+=	share/zyGrib/img share/zyGrib/tr

INSTALL_FILES=	img/1leftarrow.png img/1rightarrow.png img/back.png img/down.png
INSTALL_FILES+=	img/exit.png img/fileclose.png img/fileopen.png img/forward.png
INSTALL_FILES+=	img/help.png img/info.png img/network.png img/up.png
INSTALL_FILES+=	img/viewmag+.png img/viewmag-.png img/viewmag1.png
INSTALL_FILES+=	img/viewmagfit.png
INSTALL_FILES+=	maps/gis/cities.txt.gz maps/gis/countries_en.txt.gz
INSTALL_FILES+=	maps/gis/countries_fr.txt.gz
INSTALL_FILES+=	maps/gshhs/README.gshhs maps/gshhs/gshhs_c.b maps/gshhs/gshhs_l.b
INSTALL_FILES+=	maps/gshhs/wdb_borders_c.b maps/gshhs/wdb_borders_l.b
INSTALL_FILES+=	maps/gshhs/wdb_rivers_c.b maps/gshhs/wdb_rivers_l.b
INSTALL_FILES+=	tr/zyGrib_en.qm tr/zyGrib_en.ts

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/zyGrib ${PREFIX}/bin
.for f in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/zyGrib/${f}
.endfor

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
