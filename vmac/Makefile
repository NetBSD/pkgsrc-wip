# $NetBSD: Makefile,v 1.3 2003/11/13 11:12:18 bubuchka Exp $

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

# VMAC_GUI may be "motif", "gtk", or "no"
VMAC_GUI=	motif
BUILD_DEFS=	VMAC_GUI

USE_X11BASE=	YES
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-x --enable-${VMAC_GUI}gui

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

.if ${VMAC_GUI} == "motif"
.  include "../../mk/motif.buildlink2.mk"
.elif ${VMAC_GUI} == "gtk"
.  include "../../x11/gtk/buildlink2.mk"
.endif
.include "../../mk/bsd.pkg.mk"
