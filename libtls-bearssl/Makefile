# $NetBSD$

DISTNAME=		libtls-bearssl-0.3
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=michaelforney/}
GITHUB_PROJECT=		${PKGBASE}
GITHUB_RELEASE=		${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://sr.ht/~mcf/libtls-bearssl
COMMENT=		Implementation of libtls on top of BearSSL
LICENSE=		isc

USE_TOOLS+=		pkg-config gmake

PKGCONFIG_OVERRIDE+=	libtls.pc.in
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}
BUILD_TARGET=		libtls.a

.include "../../security/bearssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
