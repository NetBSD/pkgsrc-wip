# $NetBSD: Makefile,v 1.4 2005/11/02 18:00:15 thomasklausner Exp $
#

DISTNAME=		makesis_2.0.0-1
PKGNAME=	gnupoc-makesis-2.0.0
CATEGORIES=		devel
MASTER_SITES=		http://symbianos.org/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://symbianos.org/download/
COMMENT=		GNU SIS file generator for SymbianOS

USE_TOOLS+=	gmake

ONLY_FOR_PLATFORM+=	Linux-*-* # Need to check swprintf on other OSs

WRKSRC=		${WRKDIR}/makesis-2.0.0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/makesis ${PREFIX}/bin/

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
