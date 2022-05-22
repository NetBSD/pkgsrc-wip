# $NetBSD$

DISTNAME=	${GHCOMMIT}
PKGNAME=	mfoc-hardnested-0.10.9
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=nfc-tools/mfoc-hardnested/archive/}

MAINTAINER=	lefinnois@lefinnois.net
HOMEPAGE=	https://github.com/nfc-tools/mfoc-hardnested
COMMENT=	Fork of Mifare Classic Offline Cracker with proxmark hardnested code
LICENSE=	gnu-gpl-v2

GHCOMMIT=	2c25bf05a0b13827b9d06382c5d384b2e5c88238
USE_TOOLS+=	gmake automake autoconf pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
HAS_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/mfoc-hardnested-${GHCOMMIT}

pre-configure:
	cd ${WRKSRC} && autoreconf -is

.include "../../archivers/xz/buildlink3.mk"
.include "../../wip/libnfc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
