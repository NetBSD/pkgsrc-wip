# $NetBSD$

DISTNAME=	ahir-0.0.0.1608
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=mayureshw/}
GITHUB_PROJECT=	ahir
GITHUB_TAG=	2097969
DIST_SUBDIR=	${GITHUB_PROJECT}

GITHUB_SUBMODULES+=	mayureshw vctools 6c35689 ../../vctools
GITHUB_SUBMODULES+=	mayureshw petrisimu 1baebbe ../../petrisimu
GITHUB_SUBMODULES+=	mayureshw ceptool fa2b2fb ../../ceptool
GITHUB_SUBMODULES+=	mayureshw xsbcppif d63a9f2 ../../xsbcppif

MAINTAINER=	mayuresh@acm.org
HOMEPAGE=	https://github.com/mayureshw/ahir/
COMMENT=	High-Level Synthesis toolset from C to VHDL
#LICENSE=	Requested adding University of Illinois/NCSA Open Source License on pkgsrc mailing list

WRKSRC=		${WRKDIR}/ahir-20979697a8b64b6e880895cdf30c7ceefd7d3d40/v2
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

PKG_JVMS_ACCEPTED=	openjdk21

DEPENDS+=	XSB>=5.0:../../wip/xsb

.include "../../wip/antlr/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
