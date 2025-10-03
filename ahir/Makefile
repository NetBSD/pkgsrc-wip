# $NetBSD$

DISTNAME=	ahir-0.0.0.1610
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=mayureshw/}
GITHUB_PROJECT=	ahir
GITHUB_TAG=	5e583cb5f2d7c89925abd116a97da7a1e257312b
DIST_SUBDIR=	${GITHUB_PROJECT}

GITHUB_SUBMODULES+=	mayureshw vctools 5ca442d ../vctools
GITHUB_SUBMODULES+=	mayureshw petrisimu 1baebbe ../petrisimu
GITHUB_SUBMODULES+=	mayureshw ceptool 61f00c7 ../ceptool
GITHUB_SUBMODULES+=	mayureshw xsbcppif 3a96d2b ../xsbcppif
GITHUB_SUBMODULES+=	rutujaekatpure AaGeneration caf8a9d v2/AaGeneration

MAINTAINER=	mayuresh@acm.org
HOMEPAGE=	https://github.com/mayureshw/ahir/
COMMENT=	High-Level Synthesis toolset from C to VHDL
#LICENSE=	Requested adding University of Illinois/NCSA Open Source License on pkgsrc mailing list

AHIRDIR=	${WRKDIR}/ahir-${GITHUB_TAG}
BUILD_DIRS+=	${AHIRDIR}/v2
BUILD_DIRS+=	${WRKDIR}/vctools
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

# Buildlink sets XSBDIR, XSBLIBDIR
BUILDLINK_PASSTHRU_RPATHDIRS+=		${XSBLIBDIR}

MAKE_ENV+=	XSBDIR=${XSBDIR}
MAKE_ENV+=	AHIRDIR=${AHIRDIR}
MAKE_ENV+=	PETRISIMUDIR=${WRKDIR}/petrisimu
MAKE_ENV+=	CEPTOOLDIR=${WRKDIR}/ceptool
MAKE_ENV+=	XSBCPPIFDIR=${WRKDIR}/xsbcppif

PKG_JVMS_ACCEPTED=	openjdk21 openjdk-bin

# AaGeneration duplicates the header. Once the two upstreams merge, this can be removed
post-extract:
	${RM} -f ${AHIRDIR}/v2/AaGeneration/include/BGLWrap.hpp

.include "../../wip/xsb/buildlink3.mk"
.include "../../wip/antlr/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
