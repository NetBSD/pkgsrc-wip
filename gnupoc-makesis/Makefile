# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:19 othyro Exp $
#

DISTNAME=		makesis_2.0.0-1
PKGNAME=		gnupoc-makesis-2.0.0
CATEGORIES=		devel
MASTER_SITES=		http://www.symbianos.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
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
