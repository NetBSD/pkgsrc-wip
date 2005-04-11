# $NetBSD: Makefile,v 1.8 2005/04/11 21:16:11 tvierling Exp $

DISTNAME=	vMac-${VMAC_VERSION}-src
PKGNAME=	vmac-${VMAC_VERSION}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/vMac-${VMAC_VERSION}
CATEGORIES=	emulators
MASTER_SITES=	http://www.vmac.org/download/XWindows/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mishka@apk.od.ua
HOMEPAGE=	http://www.vmac.org/
COMMENT=	Macintosh Plus Emulator

VMAC_VERSION=	0.1.9.3

VMAC_MOTIFGUI?=	yes
BUILD_DEFS=	VMAC_MOTIFGUI

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
CONFIGURE_ARGS=	--with-x
.if ${VMAC_MOTIFGUI} == "yes"
CONFIGURE_ARGS+= --enable-motifgui
.endif

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
