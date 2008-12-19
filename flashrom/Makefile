# $NetBSD: Makefile,v 1.4 2008/12/19 18:15:49 jakllsch Exp $
#

DISTNAME=	flashrom-${FLASHROM_SNAP_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	#empty

MAINTAINER=	jakllsch@kollasch.net
HOMEPAGE=	http://www.coreboot.org/Flashrom
COMMENT=	Universal (coreboot/LinuxBIOS) flash utility

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+= gmake
USE_TOOLS+= date

SVN_REPOSITORIES=	flashrom
SVN_TAG=		{${FLASHROM_TAG}}
SVN_ROOT.flashrom=	svn://coreboot.org/repos/trunk/util/flashrom
SVN_MODULE.flashrom=	flashrom

pre-build:
	${CP} ${FILESDIR}/pio.h ${WRKSRC}


.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-i386 Linux-*-x86_64

.include "../../wip/mk/svn-package.mk"

WRKSRC=			${WRKDIR}/${PKGBASE}

.if ${OPSYS} == "NetBSD"

SUBST_CLASSES+=	pciutils
SUBST_FILES.pciutils=	Makefile flashrom.c
SUBST_FILES.pciutils+=	board_enable.c chipset_enable.c
SUBST_FILES.pciutils+=	spi.c it87spi.c ichspi.c sb600spi.c
SUBST_MESSAGE.pciutils=	fixing pciutils headers
SUBST_STAGE.pciutils=	pre-configure
SUBST_SED.pciutils+= -e 's,<pci/pci.h>,<pciutils/pci.h>,'
SUBST_SED.pciutils+= -e 's,-lpci,-lpciutils -lpci,g'

SUBST_CLASSES+= iopl
SUBST_FILES.iopl+=	flashrom.c
SUBST_MESSAGE.iopl=	fixing iopl
SUBST_STAGE.iopl=	pre-configure
SUBST_SED.iopl+= -e 's,iopl,${MACHINE_ARCH}_iopl,g'

MAKE_ENV+=	LDLIBS=-l${MACHINE_ARCH}

SUBST_CLASSES+=	lseek
SUBST_FILES.lseek=	flashrom.c chipset_enable.c
SUBST_MESSAGE.lseek=	fixing lseek64 and off64_t
SUBST_STAGE.lseek=	pre-configure
SUBST_SED.lseek+= -e 's,off64_t,off_t,g'
SUBST_SED.lseek+= -e 's,lseek64,lseek,g'
.endif

YESTERDAY!=	expr `date +%s` - 86399
FLASHROM_TAG!=		${DATE} +%Y%m%d
FLASHROM_SNAP_VERSION!=		${DATE} -r ${YESTERDAY} +%Y%m%d

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flashrom ${PREFIX}/sbin/flashrom
	${INSTALL_MAN} ${WRKSRC}/flashrom.8 ${PREFIX}/${PKGMANDIR}/man8/flashrom.8


.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
