# $NetBSD$

VERSION=	1.0.0
DISTNAME=	libdoom-umapinfo-${VERSION}
CATEGORIES=	games
MASTER_SITES=	https://micha.freeshell.org/libdoom-umapinfo/src/

OWNER=		micha@NetBSD.org
HOMEPAGE=	https://micha.freeshell.org/libdoom-umapinfo/
COMMENT=	Parser for Doom UMAPINFO data
LICENSE=	2-clause-bsd

PLIST_SUBST+=	VERS="${VERSION}"

PKGCONFIG_OVERRIDE+=		output/.muon/libdoom-umapinfo-1.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

MUON_REQD+=	0.3.0
.include "../../wip/muon/build.mk"

.include "../../mk/bsd.pkg.mk"
