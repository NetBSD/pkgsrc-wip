# $NetBSD: Makefile,v 1.1.1.1 2005/01/09 12:44:17 zul_ Exp $
#

DISTNAME=		eboard-extras-2	
CATEGORIES=             wip games
MASTER_SITES=           ${MASTER_SITE_SOURCEFORGE:=eboard/}

MAINTAINER=             zul@netbsd-fr.org
HOMEPAGE=               http://eboard.sourceforge.net/
COMMENT=               	Extras sets pieces and sound or eboard

NO_BUILD=YES

DISTFILES+=		${EXTRA2}${EXTRACT_SUFX}
DISTFILES+=		${EXTRA1}${EXTRACT_SUFX}

DEPENDS+=		eboard-[0-9\.]*:../../wip/eboard 

EXTRA2=			eboard-extras-2
EXTRA1=			eboard-extras-1pl2

do-configure:
	cd ${WRKDIR}/${EXTRA1} && ./configure
	cd ${WRKDIR}/${EXTRA2} && ./configure

do-install:
	cd ${WRKDIR}/${EXTRA1} && make install
	cd ${WRKDIR}/${EXTRA2} && make install

.include "../../mk/bsd.pkg.mk"
