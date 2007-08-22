# $NetBSD: Makefile,v 1.1.1.1 2007/08/22 19:18:28 briandealwis Exp $
#

VERSION=		8.38.6
SUFFIX=			-x86.x86_64

DISTNAME=		ati-xfree86-bin-init-${VERSION}
DISTFILES=		ati-driver-installer-${VERSION}${SUFFIX}.run
CATEGORIES=		x11
MASTER_SITES=		http://www2.ati.com/drivers/linux/
EXTRACT_SUFX=

MAINTAINER=		bsd@cs.ubc.ca
HOMEPAGE=		http://ati.amd.com/support/drivers/linux/linux-radeon.html
COMMENT=		ATI binary initialization driver for XFree86 4.3

# >= used, but hopefully this problem will be fixed in later releases...
DEPENDS=		ati-xfree86-bin>=8.40.4:../../wip/ati-xfree86-bin
LICENSE=		amd-software-license
LICENSE_FILE=		LICENSE

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386 NetBSD-[2-9]*-x86_64
EMUL_ARCH=		i386
#EMUL_PLATFORMS=	linux-i386
#EMUL_MODULES.linux=	compat
#SUSE_VERSION_REQD=	9.1

USE_DIRS+=		xdg-1.1
NO_BUILD=		yes
INITATIDIR=		${PREFIX}/share/${PKGBASE}
MESSAGE_SUBST+=		INITATIDIR=${INITATIDIR}

# Use ${ATIARCHNAME} to refer to the Linux-style architectures
ATIARCHNAME.i386=	x86
ATIARCHNAME.x86_64=	x86_64
ATIARCHNAME=		${ATIARCHNAME.${MACHINE_ARCH}}

.include "../../mk/bsd.prefs.mk"

do-extract:
	${SH} ${DISTDIR}/${DISTFILES:Q} --extract ${WRKSRC}
	${SED} \
	    -e 's;@INITATIDIR@;${INITATIDIR};g' \
	    -e 's;@X11BASE@;${X11BASE};g' \
		${FILESDIR}/XF86Config > ${WRKSRC}/XF86Config.initati
	${SED} -e 's;@INITATIDIR@;${INITATIDIR};g' \
	    ${FILESDIR}/initati > ${WRKSRC}/initati

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/initati ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${INITATIDIR}
	${INSTALL_LIB} \
		${WRKSRC}/x430/usr/X11R6/lib/modules/drivers/fglrx_drv.o \
		${INITATIDIR}
	${INSTALL_DATA} ${WRKSRC}/XF86Config.initati ${INITATIDIR}

.include "../../mk/emulator/linux.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
