# $NetBSD: Makefile,v 1.7 2012/09/24 16:56:39 asau Exp $
#

VERSION=	8.38.6
SUFFIX=		-x86.x86_64

DISTNAME=	ati-xfree86-bin-${VERSION}
DISTFILES=	ati-driver-installer-${VERSION}${SUFFIX}.run
CATEGORIES=	x11
MASTER_SITES=	http://www2.ati.com/drivers/linux/
EXTRACT_SUFX=

MAINTAINER=	bsd@cs.ubc.ca
HOMEPAGE=	http://ati.amd.com/support/drivers/linux/linux-radeon.html
COMMENT=	ATI proprietary binary drivers for XFree86 4.3
LICENSE=	amd-software-license
LICENSE_FILE=	LICENSE

PKG_DESTDIR_SUPPORT=	none

NO_BUILD=	yes

# Note: untested on all but NetBSD-4.99.[23]?-i386
# Please send feedback to ${MAINTAINER}
ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386 NetBSD-[2-9]*-x86_64
EMUL_ARCH=		i386

# Use ${ATIARCHNAME} to refer to the Linux-style architecture name
ATIARCHNAME.i386=	x86
ATIARCHNAME.x86_64=	x86_64
ATIARCHNAME=		${ATIARCHNAME.${MACHINE_ARCH}}

.include "../../mk/bsd.prefs.mk"

do-extract:
	${SH} ${DISTDIR}/${DISTFILES:Q} --extract ${WRKSRC}
	${SED} -e 's;@PREFIX@;${PREFIX};g' -e 's;@X11BASE@;${X11BASE};g' \
	    ${FILESDIR}/XF86Config.example > ${WRKSRC}/XF86Config.example

# haven't tried the support for atieventsd and friends
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
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/XF86Config.example \
	    ${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/emulator/linux.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
