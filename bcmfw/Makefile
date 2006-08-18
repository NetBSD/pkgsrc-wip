# $NetBSD: Makefile,v 1.2 2006/08/18 21:08:25 plunky Exp $

DISTNAME=		bcmfw-1.0
CATEGORIES=		sysutils
MASTER_SITES=		http://homepages.rya-online.net/plunky/	\
			${MASTER_SITE_SOURCEFORGE:=bluez/}
DISTFILES=		bcmfw-1.0.tar.gz			\
			bluez-firmware-1.2.tar.gz

MAINTAINER=		plunky@rya-online.net
COMMENT=		Broadcom 2033 Bluetooth Firmware Loader

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*

RCD_SCRIPTS+=		bcmfw
BUILD_DEFS+=		PKGMANDIR

FIRMWARE_DIR=		${PREFIX}/libdata/bcmfw

INSTALLATION_DIRS=	${PKGMANDIR}/man8			\
			${FIRMWARE_DIR}

SUBST_CLASSES+=		dir
SUBST_FILES.dir=	bcmfw.8 bcmfw.c
SUBST_SED.dir=		-e 's,BCM2033-,${FIRMWARE_DIR}/&,'
SUBST_STAGE.dir=	post-patch
SUBST_MESSAGE.dir=	Fixing path to firmware directory.

post-install:
	${INSTALL_DATA} ${WRKDIR}/bluez-firmware-1.2/broadcom/BCM-LEGAL.txt ${FIRMWARE_DIR}
	${INSTALL_DATA} ${WRKDIR}/bluez-firmware-1.2/broadcom/BCM2033-FW.bin ${FIRMWARE_DIR}
	${INSTALL_DATA} ${WRKDIR}/bluez-firmware-1.2/broadcom/BCM2033-MD.hex ${FIRMWARE_DIR}

.include "../../mk/bsd.pkg.mk"
