# $NetBSD: Makefile,v 1.5 2004/05/02 21:12:47 blef Exp $

DISTNAME=	vMac-${VMAC_VERSION}-src
PKGNAME=	vmac-${VMAC_VERSION}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/vMac-${VMAC_VERSION}
CATEGORIES=	emulators
MASTER_SITES=	http://www.leb.net/vmac/download/XWindows/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mishka@terabyte.com.ua
HOMEPAGE=	http://www.vmac.org/
COMMENT=	Macintosh Plus Emulator

VMAC_VERSION=	0.1.9.3

VMAC_MOTIFGUI?=	yes
BUILD_DEFS=	VMAC_MOTIFGUI

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_X11BASE=	YES
CONFIGURE_ARGS=	--with-x
.if ${VMAC_MOTIFGUI} == "yes"
CONFIGURE_ARGS+= --enable-motifgui
.endif

post-extract:
		${RM} -f ${WRKSRC}/config.cache
		${GZCAT} ${WRKSRC}/vmac.1.gz > ${WRKSRC}/vmac.0

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/vMac ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/vmac.0 ${PREFIX}/man/man1
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vMac
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/vMac
		${INSTALL_DATA} ${WRKSRC}/README.rom ${PREFIX}/share/doc/vMac
		${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/vMac
		${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/vMac
		${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/vMac

.if ${VMAC_MOTIFGUI} == "yes"
.include "../../mk/motif.buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
