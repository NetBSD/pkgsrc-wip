# $NetBSD$

DISTNAME=		vmailmgr-${GITHUB_TAG}
PKGNAME=		vmailmgr-0.97.0.20150901
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=bruceg/}
GITHUB_TAG=		526d53c1d0e604ec29ada61b79485ceeb8b978cd

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/vmailmgr/
COMMENT=		Manage multiple mail domains on a single qmail host
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		autoconf automake gmake perl sh
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

post-extract:
	cd ${WRKSRC}/lib/config && ${SH} build-config.sh

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../mk/bsd.pkg.mk"
