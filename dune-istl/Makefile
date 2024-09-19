# $NetBSD: Makefile,v 1.1 2012/09/16 00:00:25 jihbed Exp $
#

.include "../../wip/dune-common/Makefile.version"
.include "../../wip/dune-common/Makefile.common"


DISTNAME=	dune-istl-${DUNE-VERSION}
COMMENT=	Iterative Solver Template Library

WRKSRC=		${WRKDIR}/${DISTNAME}

CHECK_PORTABILITY_SKIP=	configure

LDFLAGS+=	-L${BUILDLINK_PREFIX.superlu}/lib

DEPENDS+=	metis>=4.0:../../math/metis

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/superlu/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../wip/dune-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
