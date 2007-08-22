# $NetBSD: Makefile,v 1.3 2007/08/22 20:51:54 briandealwis Exp $
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
LICENSE_FILE=	LICENSE
ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386 NetBSD-[2-9]*-x86_64
EMUL_ARCH=	i386

# Use ${ATIARCHNAME} to refer to the Linux-style architecture name
ATIARCHNAME.i386=	x86
ATIARCHNAME.x86_64=x86_64
ATIARCHNAME=	${ATIARCHNAME.${MACHINE_ARCH}}

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
		${WRKSRC}/arch/${ATIARCHNAME}/usr/X11R6/bin/aticonfig \
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
