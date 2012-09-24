# $NetBSD: Makefile,v 1.4 2012/09/24 16:56:39 asau Exp $
#

VERSION=	8.40.4
SUFFIX=		-x86.x86_64

DISTNAME=	ati-xfree86-bin-unstable-${VERSION}
DISTFILES=	ati-driver-installer-${VERSION}${SUFFIX}.run
CATEGORIES=	x11
MASTER_SITES=	http://www2.ati.com/drivers/linux/
EXTRACT_SUFX=

MAINTAINER=	bsd@cs.ubc.ca
HOMEPAGE=	http://ati.amd.com/support/drivers/linux/linux-radeon.html
COMMENT=	ATI binary drivers for XFree86 4.3
LICENSE=	amd-software-license
LICENSE_FILE=	LICENSE

PKG_DESTDIR_SUPPORT=	none

DEPENDS=	ati-xfree86-bin<${VERSION}:../../wip/ati-xfree86-bin

NO_BUILD=	yes
SHAREDIR=	${PREFIX}/share/${PKGBASE}
MESSAGE_SUBST+=	SHAREDIR=${SHAREDIR}

# Note: untested on all but NetBSD-4.99.[23]?-i386
ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386 NetBSD-[2-9]*-x86_64
EMUL_ARCH=		i386

# Use ${ATIARCHNAME} to refer to the Linux-style architecture name
ATIARCHNAME.i386=	x86
ATIARCHNAME.x86_64=	x86_64
ATIARCHNAME=		${ATIARCHNAME.${MACHINE_ARCH}}

# 8.40.4 seems to have a problem initializing some cards,
# causing system hangs.  Starting an X with a previous version
# seems to cure these issues.  PKGMODULESDIR should correspond
# to the location where the stable driver was installed
X11MODULESDIR=	${X11BASE}/lib/modules
PKGMODULESDIR=	${PREFIX}/lib/modules

.include "../../mk/bsd.prefs.mk"

do-extract:
	${SH} ${DISTDIR}/${DISTFILES:Q} --extract ${WRKSRC}
	${SED} -e 's;@X11MODULESDIR@;${X11MODULESDIR};g' \
	    -e 's;@PKGMODULESDIR@;${PKGMODULESDIR};g' \
	    -e 's;@ATIUNSTMODULESDIR@;${SHAREDIR}/modules;g' \
	    ${FILESDIR}/XF86Config.example > ${WRKSRC}/XF86Config.example
	${SED} -e 's;@SHAREDIR@;${SHAREDIR};g' \
	    ${FILESDIR}/initati > ${WRKSRC}/initati
	${SED} -e 's;@X11MODULESDIR@;${X11MODULESDIR};g' \
	    -e 's;@PKGMODULESDIR@;${PKGMODULESDIR};g' \
	    ${FILESDIR}/XF86Config.initati > ${WRKSRC}/XF86Config.initati

# haven't tried the support for atieventsd and friends
# /etc/ati/control and /etc/ati/signature are necessary to avoid
# the "AMD Testing Use Only" watermark
do-install:
	${INSTALL_LIB_DIR} ${SHAREDIR}
	${INSTALL_LIB_DIR} ${SHAREDIR}/modules
	${INSTALL_PROGRAM} \
		${WRKSRC}/arch/${ATIARCHNAME}/usr/X11R6/bin/aticonfig \
		${SHAREDIR}
	${INSTALL_LIB} \
		${WRKSRC}/x430/usr/X11R6/lib/modules/drivers/fglrx_drv.o \
		${WRKSRC}/x430/usr/X11R6/lib/modules/linux/libfglrxdrm.a \
		${SHAREDIR}/modules
	${INSTALL_DATA_DIR} ${PREFIX}/etc/ati
	${INSTALL_DATA} \
	    ${WRKSRC}/common/etc/ati/control \
	    ${WRKSRC}/common/etc/ati/signature \
	    ${PREFIX}/etc/ati/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/XF86Config.example \
	    ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_SCRIPT} ${WRKSRC}/initati ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/XF86Config.initati \
	    ${SHAREDIR}

.include "../../mk/emulator/linux.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
