# $NetBSD: Makefile,v 1.1 2012/09/15 23:59:12 jihbed Exp $
#

.include "../../wip/dune-common/Makefile.version"
.include "../../wip/dune-common/Makefile.common"

DISTNAME=	dune-geometry-${DUNE-VERSION}
CATEGORIES=	math
COMMENT=	Includes everything related to the DUNE reference elements

WRKSRC=		${WRKDIR}/${DISTNAME}

CHECK_PORTABILITY_SKIP=	configure

PKGCONFIG_OVERRIDE+=	dune-geometry-2.2.0/PaxHeaders.17347/dune-geometry.pc.in
PKGCONFIG_OVERRIDE+=	dune-geometry-2.2.0/dune-geometry.pc.in

.include "../../wip/dune-common/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
