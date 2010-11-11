# $NetBSD: Makefile,v 1.6 2010/11/11 22:42:06 shattered Exp $
#

DISTNAME=	flashrom-0.9.0
CATEGORIES=	sysutils
MASTER_SITES=	http://qa.flashrom.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://www.flashrom.org/Flashrom
COMMENT=	Universal (coreboot/LinuxBIOS) flash utility

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+= gmake

pre-build:
	${CP} ${FILESDIR}/pio.h ${WRKSRC}

.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-i386 Linux-*-x86_64

.if ${OPSYS} == "NetBSD"

SUBST_CLASSES+=	pciutils
SUBST_FILES.pciutils=	Makefile flashrom.c
SUBST_FILES.pciutils+=	board_enable.c chipset_enable.c
SUBST_FILES.pciutils+=	spi.c it87spi.c ichspi.c sb600spi.c wbsio_spi.c
SUBST_MESSAGE.pciutils=	fixing pciutils headers
SUBST_STAGE.pciutils=	pre-configure
SUBST_SED.pciutils+= -e 's,<pci/pci.h>,<pciutils/pci.h>,'
SUBST_SED.pciutils+= -e 's,-lpci,-lpciutils -lpci,g'

.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flashrom ${PREFIX}/sbin/flashrom
	${INSTALL_MAN} ${WRKSRC}/flashrom.8 ${PREFIX}/${PKGMANDIR}/man8/flashrom.8

.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
