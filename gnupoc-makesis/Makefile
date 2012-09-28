# $NetBSD: Makefile,v 1.6 2012/09/29 00:27:47 asau Exp $
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

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/makesis ${DESTDIR}${PREFIX}/bin/

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
