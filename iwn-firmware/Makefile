# $NetBSD: Makefile,v 1.1.1.1 2008/02/10 00:29:37 h2m Exp $
#

DISTNAME=		iwlwifi-4965-ucode-${PKG_VERSION}
PKGNAME=		iwn-firmware-${PKG_VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		http://intellinuxwireless.org/iwlwifi/downloads/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://intelliwireless.org/
COMMENT=		Firmware binary image for the iwn(4) driver

NO_CONFIGURE=		yes
NO_BUILD=		yes

PKG_VERSION=		4.44.1.20
FIRMNAME=		iwlwifi-4965.ucode

pre-install:
	cd ${WRKSRC} && \
	${MV} iwlwifi-4965-1.ucode ${FIRMNAME}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/if_iwn
	${INSTALL_DATA} ${WRKSRC}/LICENSE.iwlwifi-4965-ucode ${PREFIX}/libdata/if_iwn
	${INSTALL_DATA} ${WRKSRC}/README.iwlwifi-4965-ucode ${PREFIX}/libdata/if_iwn
	${INSTALL_DATA} ${WRKSRC}/${FIRMNAME} ${PREFIX}/libdata/if_iwn

.include "../../mk/bsd.pkg.mk"
