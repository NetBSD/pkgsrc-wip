# $NetBSD: Makefile,v 1.1.1.1 2007/08/15 23:44:32 briandealwis Exp $
#

DISTNAME=	ati-xfree86-bin-8.40.4
DISTFILES=	ati-driver-installer-8.40.4-x86.x86_64.run
CATEGORIES=	x11
MASTER_SITES=	http://www2.ati.com/drivers/linux/
EXTRACT_SUFX=

MAINTAINER=	bsd@cs.ubc.ca
HOMEPAGE=	http://ati.amd.com/support/drivers/linux/linux-radeon.html
COMMENT=	ATI binary drivers for XFree86 4.3

NO_BUILD=	yes
USE_DIRS+=	xdg-1.1

LICENSE=	amd-software-license
ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386 NetBSD-[2-9]*-x86_64

EMUL_PLATFORMS=         linux-i386
EMUL_MODULES.linux=     compat
SUSE_VERSION_REQD=      9.1

# Use ${ARCHNAME} to refer to the Linux-style architectures
ARCHNAME.i386=	x86
ARCHNAME.x86_64=x86_64
ARCHNAME=	${ARCHNAME.${MACHINE_ARCH}}

.include "../../mk/bsd.prefs.mk"

do-extract:
	${SH} ${DISTDIR}/${DISTFILES:Q} --extract ${WRKSRC}
	${SED} -e 's;@PREFIX@;${PREFIX};g' ${FILESDIR}/XF86Config \
	    > ${WRKSRC}/XF86Config.example

# haven't tried the support for atieventsd and friends
# /etc/ati/control and /etc/ati/signature are necessary to avoid
# the "AMD Testing Use Only" watermark
do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/arch/${ARCHNAME}/usr/X11R6/bin/aticonfig \
		${X11PREFIX}/bin
	${INSTALL_LIB_DIR} ${X11PREFIX}/lib/modules/drivers
	${INSTALL_LIB} \
		${WRKSRC}/x430/usr/X11R6/lib/modules/drivers/fglrx_drv.o \
		${X11PREFIX}/lib/modules/drivers/
	${INSTALL_LIB_DIR} ${X11PREFIX}/lib/modules/linux
	${INSTALL_LIB} \
		${WRKSRC}/x430/usr/X11R6/lib/modules/linux/libfglrxdrm.a \
		${X11PREFIX}/lib/modules/linux/
	${INSTALL_DATA_DIR} ${PREFIX}/etc/ati
	${INSTALL_DATA} \
	    ${WRKSRC}/common/etc/ati/control \
	    ${WRKSRC}/common/etc/ati/signature \
	    ${PREFIX}/etc/ati/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/XF86Config.example \
	    ${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/emulator/linux.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
