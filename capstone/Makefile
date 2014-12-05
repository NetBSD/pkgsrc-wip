# $NetBSD: Makefile,v 1.3 2014/12/05 11:49:14 thomasklausner Exp $

DISTNAME=	capstone-3.0
CATEGORIES=	devel
MASTER_SITES=	http://www.capstone-engine.org/download/${PKGVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.capstone-engine.org/
COMMENT=	lightweight multi-platform, multi-architecture disassembly framework
LICENSE=	modified-bsd	

PKGCONFIG_OVERRIDE+=	capstone.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build
USE_TOOLS+=	gmake
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
