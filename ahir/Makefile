# $NetBSD$

DISTNAME=	ahir-0.0.0.1608
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=mayureshw/}
GITHUB_PROJECT=	ahir
GITHUB_TAG=	2097969
DIST_SUBDIR=	${GITHUB_PROJECT}

GITHUB_SUBMODULES+=	mayureshw vctools 172554d ../vctools
GITHUB_SUBMODULES+=	mayureshw petrisimu 1baebbe ../petrisimu
GITHUB_SUBMODULES+=	mayureshw ceptool fa2b2fb ../ceptool
GITHUB_SUBMODULES+=	mayureshw xsbcppif b46ea46 ../xsbcppif

MAINTAINER=	mayuresh@acm.org
HOMEPAGE=	https://github.com/mayureshw/ahir/
COMMENT=	High-Level Synthesis toolset from C to VHDL
#LICENSE=	Requested adding University of Illinois/NCSA Open Source License on pkgsrc mailing list

AHIRDIR=	${WRKDIR}/ahir-20979697a8b64b6e880895cdf30c7ceefd7d3d40
BUILD_DIRS+=	${AHIRDIR}/v2
BUILD_DIRS+=	${WRKDIR}/vctools
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

# Some tools suh as Aa2VC SEGV if -O is enabled
CFLAGS:=	${CFLAGS:C/-O[0-9]*/-O0/}

# Buildlink sets XSBDIR, XSBLIBDIR
BUILDLINK_PASSTHRU_RPATHDIRS+=		${XSBLIBDIR}

MAKE_ENV+=	XSBDIR=${XSBDIR}
MAKE_ENV+=	AHIRDIR=${AHIRDIR}
MAKE_ENV+=	PETRISIMUDIR=${WRKDIR}/petrisimu
MAKE_ENV+=	CEPTOOLDIR=${WRKDIR}/ceptool
MAKE_ENV+=	XSBCPPIFDIR=${WRKDIR}/xsbcppif

PKG_JVMS_ACCEPTED=	openjdk21 openjdk-bin

.include "../../wip/xsb/buildlink3.mk"
.include "../../wip/antlr/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
