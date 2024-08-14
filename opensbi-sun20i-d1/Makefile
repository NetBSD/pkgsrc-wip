# $NetBSD: Makefile,v 1.1 2024/07/18 08:51:14 rxg Exp $

OPENSBI_VERSION=	1.2
DISTINFO_FILE=		${.CURDIR}/distinfo
GITHUB_TAG=		v${OPENSBI_VERSION}

OPENSBI_BOARD=		sun20i-d1
OPENSBI_PLATFORM=	generic

MAKE_ENV+=		FW_PIC=y

OPENSBI_BIN=		fw_dynamic.bin

.include "../../sysutils/opensbi/opensbi.mk"
.include "../../mk/bsd.pkg.mk"
