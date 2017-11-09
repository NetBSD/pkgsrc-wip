# $NetBSD$

DISTNAME=	hashcat-4.0.1
CATEGORIES=	security
MASTER_SITES=	https://hashcat.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hashcat.net/
COMMENT=	World's fastest and most advanced password recovery utility
LICENSE=	mit

USE_TOOLS+=	gmake gsed
BUILD_TARGET=	hashcat

SUBST_CLASSES+=		ver-tag
SUBST_STAGE.ver-tag=	pre-configure
SUBST_MESSAGE.ver-tag=	Planting custom version tag.
SUBST_FILES.ver-tag=	src/Makefile
SUBST_SED.ver-tag=	-e 's,@VERSION_TAG@,${PKGVERSION_NOREV}-pkgsrc,'

.include "../../mk/bsd.pkg.mk"
