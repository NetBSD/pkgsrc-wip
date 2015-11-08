# $NetBSD: Makefile,v 1.5 2015/04/21 17:02:51 joerg Exp $

DISTNAME=	FlightGear-data-3.4.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Shared/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Shared/ \
		ftp://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Shared/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.flightgear.org/
COMMENT=	FlightGear Simulator data files
LICENSE=	gnu-gpl-v2

UNLIMIT_RESOURCES+=	cputime

WRKSRC=			${WRKDIR}/fgdata
NO_BUILD=		yes
NO_CONFIGURE=		yes

DATASUBDIR=	lib/FlightGear
DATADIR=	${PREFIX}/${DATASUBDIR}
PLIST_SRC=	PLIST ${WRKDIR}/PLIST.F

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DATADIR}
	# auto-generated PLIST
	rm -f ${WRKDIR}/PLIST.F
	set -e;	cd ${WRKSRC} &&						\
	find . -type d -print | while read d; do			\
		${INSTALL_DATA_DIR} ${DESTDIR}${DATADIR}/"$${d}";	\
	done;								\
	find . -type f -print | while read f; do			\
		${INSTALL_DATA} "$${f}" ${DESTDIR}${DATADIR}/"$${f}";	\
		${ECHO} ${DATASUBDIR}/"$${f#./}" >> ${WRKDIR}/PLIST.F;	\
	done;

.include "../../mk/bsd.pkg.mk"
