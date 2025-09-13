# $NetBSD$

DISTNAME=	ahir-0.0.0.1608
#PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=mayureshw/}
GITHUB_PROJECT=	ahir
GITHUB_TAG=	2097969
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	mayuresh@acm.org
HOMEPAGE=	https://github.com/mayureshw/ahir/
COMMENT=	High-Level Synthesis toolset from C to VHDL
#LICENSE=	Requested adding University of Illinois/NCSA Open Source License on pkgsrc mailing list

WRKSRC=		${WRKDIR}/ahir-20979697a8b64b6e880895cdf30c7ceefd7d3d40/v2
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

PKG_JVMS_ACCEPTED=	openjdk21

.include "../../wip/antlr/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
