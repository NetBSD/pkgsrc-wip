# $NetBSD: Makefile,v 1.1.1.1 2003/05/23 23:23:02 bubuchka Exp $

DISTNAME=	vMac-${VMAC_VERSION}-src
PKGNAME=	vmac-${VMAC_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.leb.net/vmac/download/XWindows/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc@netbsd.org
HOMEPAGE=	http://www.vmac.org/
COMMENT=	Macintosh Plus Emulator

VMAC_VERSION=	0.1.9.3

USE_X11BASE=	YES
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-motifgui

WRKSRC=		${WRKDIR}/vMac-${VMAC_VERSION}

pre-configure:
		${RM} -f ${WRKSRC}/config.cache

post-build:
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

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
