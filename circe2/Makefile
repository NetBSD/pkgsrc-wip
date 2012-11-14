# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:01 othyro Exp $
#

DISTNAME=	circe2-2.0.5
CATEGORIES=	math
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
