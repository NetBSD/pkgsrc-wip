# $NetBSD$

DISTNAME=	ahir-0.0.0.1609
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=mayureshw/}
GITHUB_PROJECT=	ahir
GITHUB_TAG=	d0c06f7
DIST_SUBDIR=	${GITHUB_PROJECT}

GITHUB_SUBMODULES+=	mayureshw vctools 5ca442d ../vctools
GITHUB_SUBMODULES+=	mayureshw petrisimu 1baebbe ../petrisimu
GITHUB_SUBMODULES+=	mayureshw ceptool 61f00c7 ../ceptool
GITHUB_SUBMODULES+=	mayureshw xsbcppif 3a96d2b ../xsbcppif

MAINTAINER=	mayuresh@acm.org
HOMEPAGE=	https://github.com/mayureshw/ahir/
COMMENT=	High-Level Synthesis toolset from C to VHDL
#LICENSE=	Requested adding University of Illinois/NCSA Open Source License on pkgsrc mailing list

AHIRDIR=	${WRKDIR}/ahir-d0c06f712ecb6f03c007c17c714aac9d8ee8c12e
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

.include "../../wip/xsb/buildlink3.mk"
.include "../../wip/antlr/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
