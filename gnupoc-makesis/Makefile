# $NetBSD: Makefile,v 1.5 2007/06/11 10:50:12 shattered Exp $
#

DISTNAME=		makesis_2.0.0-1
PKGNAME=		gnupoc-makesis-2.0.0
CATEGORIES=		devel
MASTER_SITES=		http://www.symbianos.org/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.symbianos.org/download/
COMMENT=		GNU SIS file generator for SymbianOS

USE_TOOLS+=	gmake

ONLY_FOR_PLATFORM+=	Linux-*-* # Need to check swprintf on other OSs

WRKSRC=		${WRKDIR}/makesis-2.0.0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/makesis ${PREFIX}/bin/

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
