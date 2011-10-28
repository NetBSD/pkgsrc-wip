# $NetBSD: Makefile,v 1.1.1.1 2011/10/28 17:51:07 jihbed Exp $
#

DISTNAME=	circe2-2.0.5
CATEGORIES=	physics
MASTER_SITES=	http://www.hepforge.org/archive/whizard/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.hepforge.org/archive/whizard/
COMMENT=	CIRCE1 is WHIZARD's generator for lepton collider beamstrahlung
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c fortran

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
