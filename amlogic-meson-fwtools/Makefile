# $NetBSD: Makefile,v 1.4 2019/11/04 21:28:40 rillig Exp $

# Version isn't super-meaningful; we're grabbing a collection of non-changing
# tools from a variety of locations.
VERSION=	0.0

PKGNAME=	amlogic-meson-fwtools-${VERSION}
PKGREVISION=	2		# bump this when a tool is added/removed
CATEGORIES=	sysutils

MAINTAINER=	port-arm@NetBSD.org
COMMENT=	Trusted Firmware packaging tools for the Amlogic Meson family of SoCs

LICENSE=	amlogic-meson-fwtools-license

RESTRICTED=		Redistribution not permitted - see licenses/amlogic-meson-fwtools
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

#
# These tools are distributed only as Linux x86_64 binaries.
#

EMUL_PLATFORMS=		linux-x86_64
EMUL_MODULES.linux=	base

NO_CONFIGURE=	yes
NO_BUILD=	yes

#
# Hardkernel-supplied firmware tools
#
ODROID=			odroidc2-v2015.01

xFIPCREATE=		fip_create
FIPCREATE=		${ODROID}-${xFIPCREATE}
DISTFILES+=		${FIPCREATE}
SITES.${FIPCREATE}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}hardkernel/u-boot/raw/${ODROID}/fip/${xFIPCREATE} @}

xAML_ENCRYPT_GXB=		aml_encrypt_gxb
AML_ENCRYPT_GXB=		${ODROID}-${xAML_ENCRYPT_GXB}
DISTFILES+=			${AML_ENCRYPT_GXB}
SITES.${AML_ENCRYPT_GXB}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}hardkernel/u-boot/raw/${ODROID}/fip/gxb/${xAML_ENCRYPT_GXB} @}

#
# Khadas-supplied firmware tools
#
KHADAS=			khadas-vims-v2015.01

xAML_ENCRYPT_G12B=		aml_encrypt_g12b
AML_ENCRYPT_G12B=		${KHADAS}-${xAML_ENCRYPT_G12B}
DISTFILES+=			${AML_ENCRYPT_G12B}
SITES.${AML_ENCRYPT_G12B}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/g12b/${xAML_ENCRYPT_G12B} @}

xAML_ENCRYPT_G12A=		aml_encrypt_g12a
AML_ENCRYPT_G12A=		${KHADAS}-${xAML_ENCRYPT_G12A}
DISTFILES+=			${AML_ENCRYPT_G12A}
SITES.${AML_ENCRYPT_G12B}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}khadas/u-boot/raw/${KHADAS}/fip/g12a/${xAML_ENCRYPT_G12A} @}

#
# BayLibre-supplied firmware tools
#
LIBRETECH=		libretech-cc

xAML_ENCRYPT_GXL=		aml_encrypt_gxl
AML_ENCRYPT_GXL=		${LIBRETECH}-${xAML_ENCRYPT_GXL}
DISTFILES+=			${AML_ENCRYPT_GXL}
SITES.${AML_ENCRYPT_GXL}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}BayLibre/u-boot/raw/${LIBRETECH}/fip/gxl/${xAML_ENCRYPT_GXL} @}

xAML_BLX_FIX_G12A=		blx_fix_g12a.sh
AML_BLX_FIX_G12A=		${LIBRETECH}-${xAML_BLX_FIX_G12A}
DISTFILES+=			${AML_BLX_FIX_G12A}
# Origin script by BayLibre, but only works for linux.
#SITES.${AML_BLX_FIX_G12A}=	${MASTER_SITE_GITHUB:@url@ \
#	-${url}BayLibre/u-boot/releases/download/v2017.11-${LIBRETECH}/${xAML_BLX_FIX_G12A} @}

# Updated version for os compability with both linux and bsd.
SITES.${AML_BLX_FIX_G12A}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}thirdyouth/u-boot-blobs/raw/main/amlogic/${xAML_BLX_FIX_G12A} @}

INSTALLATION_DIRS+=	bin

do-extract:
	# Nothing to do.
	${TRUE}

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${FIPCREATE} \
		${DESTDIR}${PREFIX}/bin/aml_fip_create
	${INSTALL_PROGRAM} ${DISTDIR}/${AML_ENCRYPT_GXB} \
		${DESTDIR}${PREFIX}/bin/aml_encrypt_gxb
	${INSTALL_PROGRAM} ${DISTDIR}/${AML_ENCRYPT_GXL} \
		${DESTDIR}${PREFIX}/bin/aml_encrypt_gxl
	${INSTALL_PROGRAM} ${DISTDIR}/${AML_ENCRYPT_G12B} \
		${DESTDIR}${PREFIX}/bin/aml_encrypt_g12b
	${INSTALL_PROGRAM} ${DISTDIR}/${AML_ENCRYPT_G12A} \
		${DESTDIR}${PREFIX}/bin/aml_encrypt_g12a
	${INSTALL_DATA} ${DISTDIR}/${AML_BLX_FIX_G12A} \
		${DESTDIR}${PREFIX}/bin/blx_fix_g12a.sh

.include "../../mk/bsd.pkg.mk"
