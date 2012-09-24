# $NetBSD: Makefile,v 1.2 2012/09/24 18:26:53 asau Exp $
#

DISTNAME=	circe2-2.0.5
CATEGORIES=	physics
MASTER_SITES=	http://www.hepforge.org/archive/whizard/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.hepforge.org/archive/whizard/
COMMENT=	CIRCE1 is WHIZARD's generator for lepton collider beamstrahlung
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c fortran

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
