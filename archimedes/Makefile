# $NetBSD: Makefile,v 1.10 2013/12/11 19:53:28 gschwarz Exp $

DISTNAME=	archimedes-2.0.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=archimedes/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/archimedes/
COMMENT=	2D Monte Carlo simulation software for submicron semiconductor devices
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_FEATURES+=	getopt_long

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
SUBST_CLASSES+=	inline
SUBST_STAGE.inline=        pre-configure
SUBST_FILES.inline=        src/particlecreation.h
SUBST_MESSAGE.inline=      Removing inline due to compiler compatibility issues
SUBST_SED.inline=         -e s,inline,,
.endif

.include "../../mk/bsd.pkg.mk"
