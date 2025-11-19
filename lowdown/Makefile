# $NetBSD$

DISTNAME=		lowdown-2.0.4
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=kristapsdz/}
GITHUB_TAG=		refs/tags/VERSION_${PKGVERSION_NOREV:S/./_/g}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://kristaps.bsd.lv/lowdown/
COMMENT=		Simple Markdown translator
LICENSE=		isc

WRKSRC=			${WRKDIR}/${PKGBASE}-${GITHUB_TAG:C/.*\///}

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		PREFIX=${PREFIX}

INSTALL_TARET=		install
TEST_TARGET=		regress

.include "../../mk/bsd.pkg.mk"
