# $NetBSD: Makefile,v 1.2 2005/04/11 21:12:32 tvierling Exp $
#

DISTNAME=		makesis_2.0.0-1
PKGNAME=	gnupoc-makesis-2.0.0
CATEGORIES=		wip devel
MASTER_SITES=		http://symbianos.org/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://symbianos.org/download/
COMMENT=		GNU SIS file generator for SymbianOS

USE_GNU_TOOLS+=	make

ONLY_FOR_PLATFORM+=	Linux-*-* # Need to check swprintf on other OSs

WRKSRC=		${WRKDIR}/makesis-2.0.0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/makesis ${PREFIX}/bin/

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
