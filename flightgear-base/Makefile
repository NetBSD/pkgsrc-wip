# $NetBSD: Makefile,v 1.4 2005/05/08 06:54:51 obache Exp $
#

DISTNAME=	fgfs-base-0.9.3
PKGNAME=	${DISTNAME:S/fgfs/flightgear/}
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Shared/ \
		ftp://ftp.sunsite.org.uk/sites/ftp.flightgear.org/flightgear-ftp/Shared/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Shared/ \
		http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Shared/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Shared/ \
		ftp://obgyn.edu.pl/fgfs/Shared/
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	ftp://ftp.flightgear.org/pub/fgfs/Shared/
COMMENT=	FlightGear Simulator (data files)

WRKSRC=		${WRKDIR}/FlightGear-0.9.3/data
NO_BUILD=	yes
USE_LANGUAGES=	# empty

FG_SHAREDIR=	${PREFIX}/lib/FlightGear

do-install:
.if !exists(${FG_SHAREDIR})
	@${INSTALL_DATA_DIR} ${FG_SHAREDIR}
.endif
	(						    \
	cd ${WRKSRC};					    \
	${FIND} . -type f -name .\* -print|${XARGS} rm -f;  \
	${PAX} -rwppm . ${FG_SHAREDIR};			    \
	)

.include "../../mk/bsd.pkg.mk"
