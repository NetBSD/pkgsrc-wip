# $NetBSD: Makefile,v 1.1.1.1 2010/08/29 09:37:38 ggergely Exp $
#

VERSION=	0.3.1
DISTNAME=	openmsx-${VERSION}-all
PKGNAME=	openttd-${DISTNAME:S/-all$//}
CATEGORIES=	games
MASTER_SITES=	http://binaries.openttd.org/extra/openmsx/${VERSION}/
EXTRACT_SUFX=	.zip

MAINTAINER=	elentirmo.gilgalad@gmail.com
HOMEPAGE=	http://openttd.org/
COMMENT=	Free and open source music data files for the game OpenTTD
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=  	share/openttd/data

WRKSRC=		${WRKDIR}/openmsx-${VERSION}
USE_LANGUAGES=	# none

NO_BUILD=		YES
NO_CONFIGURE=		YES

MUSIC_FILES_LIST= busy_schedule.mid \
	chemistry_lab.mid \
	coconut_run2.mid \
	harp_harmony.mid \
	keep_on_rolling.mid \
	linns_basket.mid \
	little_blue_box_car.mid \
	midnight_snow_run.mid \
	mighty_giant_run.mid \
	modern_motion.mid \
	relax_song.mid \
	run_for_your_life.mid \
	smooth_groove.mid \
	the_fast_route.mid \
	train_filled_with_cash.mid \
	tttheme2.mid \
	ultimate_run.mid \
	wood_whistles.mid \


do-install:
	for m in ${MUSIC_FILES_LIST}; do \
		${INSTALL_DATA} ${WRKSRC}/$$m \
	   	${DESTDIR}${PREFIX}/share/openttd/data; \
	done


.include "../../mk/bsd.pkg.mk"
