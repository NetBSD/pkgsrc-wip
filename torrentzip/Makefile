# $NetBSD: Makefile,v 1.8 2021/03/03 12:05:41 nia Exp $

DISTNAME=	TrrntZip.NET200Linux
PKGNAME=	torrentzip-2.0.0
CATEGORIES=	archivers
MASTER_SITES=	https://romvault.com/trrntzip/download/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://romvault.com/trrntzip/
COMMENT=	Convert zip archives to torrentzip format
LICENSE=	apache-2.0

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	base

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin

do-build:

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/TrrntZipCMD ${DESTDIR}${PREFIX}/bin/torrentzip

.include "../../mk/bsd.pkg.mk"
