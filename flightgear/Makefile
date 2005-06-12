# $NetBSD: Makefile,v 1.5 2005/06/12 23:51:18 kristerw Exp $
#

DISTNAME=		FlightGear-0.9.3
PKGNAME=		${DISTNAME:S/FlightGear/flightgear/}
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.flightgear.org/pub/fgfs/Source/ \
			ftp://ftp.sunsite.org.uk/sites/ftp.flightgear.org/flightgear-ftp/Source/ \
			ftp://ftp.kingmont.com/flightsims/flightgear/Source/ \
			http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Source/ \
			ftp://ftp.de.flightgear.org/pub/fgfs/Source/ \
			ftp://obgyn.edu.pl/fgfs/Source/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.flightgear.org/
COMMENT=		The FlightGear Simulator

DEPENDS=		flightgear-base>=0.9.3:../../wip/flightgear-base

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-threads

.include "../../games/plib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../wip/simgear/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
