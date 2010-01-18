# $NetBSD: Makefile,v 1.2 2010/01/18 09:38:34 thomasklausner Exp $

DISTNAME=		tumble-0.33
PKGREVISION=		1
CATEGORIES=		print graphics
MASTER_SITES=		http://tumble.brouhaha.com/download/

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://tumble.brouhaha.com/
COMMENT=		Utility to construct PDF files from image files

USE_TOOLS+=		gmake
USE_TOOLS+=		bison
USE_TOOLS+=		flex

# XXX: Only little endian architectures
ONLY_FOR_PLATFORM=	*-*-i386 *-*-vax *-*-alpha

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/tumble

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tumble ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tumble

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
