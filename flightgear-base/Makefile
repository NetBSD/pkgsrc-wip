# $NetBSD: Makefile,v 1.3 2005/04/11 21:12:15 tvierling Exp $
#

DISTNAME=	fgfs-base-0.9.3
PKGNAME=	${DISTNAME:S/fgfs/flightgear/}
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Shared/

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
