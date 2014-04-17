# $NetBSD: Makefile,v 1.1 2014/04/17 00:33:17 thomasklausner Exp $

DISTNAME=	df_34_11_linux
PKGNAME=	dwarf_fortress-34.11
CATEGORIES=	games
MASTER_SITES=	http://www.bay12games.com/dwarves/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bay12games.com/dwarves/
COMMENT=	Single-player fantasy game in a randomly generated, persistent world
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/df_linux
USE_LANGUAGES=	c++

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	gtk2 libSDL

.include "../../mk/bsd.pkg.mk"
