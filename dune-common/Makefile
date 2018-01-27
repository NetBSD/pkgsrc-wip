# $NetBSD: Makefile,v 1.1 2012/09/15 23:57:55 jihbed Exp $
#

.include "../../wip/dune-common/Makefile.version"
.include "../../wip/dune-common/Makefile.common"


DISTNAME=	dune-common-${DUNE-VERSION}
COMMENT=	Contains the basic classes used by all DUNE modules


DEPENDS+=	doxygen>=1.8.2:../../devel/doxygen

CHECK_PORTABILITY_SKIP=	configure

PKGCONFIG_OVERRIDE+=	dune-common-2.2.0/PaxHeaders.15870/dune-common.pc.in
PKGCONFIG_OVERRIDE+=	dune-common-2.2.0/dune-common.pc.in

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${TOOLS_PATH.bash}
REPLACE_FILES.bash=	bin/dune-autogen bin/dunecontrol bin/dunedoxynize bin/duneproject bin/mpi-config

.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
