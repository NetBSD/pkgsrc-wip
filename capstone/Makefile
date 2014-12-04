# $NetBSD: Makefile,v 1.2 2014/12/04 18:30:16 krytarowski Exp $

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

.include "../../mk/bsd.pkg.mk"
