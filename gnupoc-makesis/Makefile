# $NetBSD: Makefile,v 1.1.1.1 2004/08/31 21:21:31 poppnk Exp $
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
USE_BUILDLINK3=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/makesis ${PREFIX}/bin/

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
