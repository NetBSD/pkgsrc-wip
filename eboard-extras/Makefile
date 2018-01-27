# $NetBSD: Makefile,v 1.8 2012/09/28 22:07:29 asau Exp $
#

DISTNAME=		eboard-extras-2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=eboard/}

MAINTAINER=		zul@netbsd-fr.org
HOMEPAGE=		http://www.bergo.eng.br/eboard/
COMMENT=		Extras sets, pieces and sound or eboard
LICENSE=		gnu-gpl-v2

NO_BUILD=	YES

DISTFILES+=		${EXTRA2}${EXTRACT_SUFX}
DISTFILES+=		${EXTRA1}${EXTRACT_SUFX}

DEPENDS+=		eboard-[0-9\.]*:../../games/eboard

EXTRA2=			eboard-extras-2
EXTRA1=			eboard-extras-1pl2

do-configure:
	cd ${WRKDIR}/${EXTRA1} && ./configure
	cd ${WRKDIR}/${EXTRA2} && ./configure

do-install:
	cd ${WRKDIR}/${EXTRA1} && ${MAKE_PROGRAM} install
	cd ${WRKDIR}/${EXTRA2} && ${MAKE_PROGRAM} install

.include "../../mk/bsd.pkg.mk"
