# $NetBSD: Makefile,v 1.1.1.1 2004/03/19 05:15:53 xtraeme Exp $
#

DISTNAME=		FlightGear-0.9.3
PKGNAME=		${DISTNAME:S/FlightGear/flightgear/}
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.flightgear.org/pub/fgfs/Source/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.flightgear.org/
COMMENT=		The FlightGear Simulator

DEPENDS=		flightgear-base>=0.9.3:../../wip/flightgear-base

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-threads

.include "../../games/plib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../wip/simgear/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
