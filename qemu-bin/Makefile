# $NetBSD: Makefile,v 1.2 2004/09/02 01:35:50 dhowland Exp $
#

DISTNAME=		qemu-0.6.0-i386
PKGNAME=		qemu-bin-0.6.0
CATEGORIES=		emulators
MASTER_SITES=		http://fabrice.bellard.free.fr/qemu/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://fabrice.bellard.free.fr/qemu/
COMMENT=		CPU emulator using dynamic translation

NO_BUILD=		# defined

CONFLICTS+=             qemu-*

ONLY_FOR_PLATFORM=      Linux-*-i386 NetBSD-*-i386

WRKSRC=			${WRKDIR}/usr/local

.include "../../emulators/suse_linux/Makefile.application"

.if ${OPSYS} != "Linux"
DEPENDS+=               suse_x11-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_x11
DEPENDS+=               suse_libjpeg-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_libjpeg
.endif

do-install:
	${INSTALL} ${WRKSRC}/bin/* ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/*.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/qemu
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/qemu
	${INSTALL_DATA} ${WRKSRC}/share/doc/qemu/*.html ${PREFIX}/share/doc/qemu
	${INSTALL_DATA} ${WRKSRC}/share/qemu/*.bin ${PREFIX}/share/qemu

.include "../../mk/bsd.pkg.mk"
