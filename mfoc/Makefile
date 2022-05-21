# $NetBSD$

DISTNAME=	${GHCOMMIT}
PKGNAME=	mfoc-0.10.7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=nfc-tools/mfoc/archive/}

MAINTAINER=	lefinnois@lefinnois.net
HOMEPAGE=	https://github.com/nfc-tools/mfoc
COMMENT=	Mifare Classic Offline Cracker
LICENSE=	gnu-gpl-v2

GHCOMMIT=	ba072f16f6b2a655d51da2171ecfb83e26c0ef58
USE_TOOLS+=	gmake automake autoconf pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
HAS_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/mfoc-${GHCOMMIT}

pre-configure:
	cd ${WRKSRC} && autoreconf -is

.include "../../wip/libnfc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
