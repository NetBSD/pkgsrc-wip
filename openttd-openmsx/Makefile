# $NetBSD: Makefile,v 1.2 2010/08/29 10:47:50 ggergely Exp $
#
PKGREVISION=	1

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

MUSIC_FILES_LIST= 5432gone_redfarn.mid \
	be_sharp_bw_redfarn.mid \
	big_man_boogie_redfarn.mid \
	boogi_marabi_redfarn.mid \
	busy_schedule.mid \
	careless_perc_redfarn.mid \
	chemistry_lab.mid \
	chuggachugga.mid \
	city_blues_redfarn.mid \
	coconut_run2.mid \
	flying_scotsman.mid \
	harp_harmony.mid \
	linns_basket.mid \
	midnight_snow_run.mid \
	mighty_giant_run.mid \
	modern_motion.mid \
	moo_redfarn.mid \
	mosey_along_redfarn.mid \
	no_work_song_redfarn.mid \
	relax_song.mid \
	run_for_your_life.mid \
	say_what_redfarn.mid \
	slow_neasy_redfarn.mid \
	the_fast_route.mid \
	the_hobo_redfarn.mid \
	train_filled_with_cash.mid \
	ttsong_iii_imuh3.mid \
	ttsong_iv_imuh3.mid \
	tttheme2.mid \
	ultimate_run.mid \
	wood_whistles.mid \
	openmsx.obm

do-install:
	for m in ${MUSIC_FILES_LIST}; do \
		${INSTALL_DATA} ${WRKSRC}/$$m \
	   	${DESTDIR}${PREFIX}/share/openttd/data; \
	done


.include "../../mk/bsd.pkg.mk"
