# $NetBSD: Makefile,v 1.5 2010/10/24 17:03:23 jakllsch Exp $
#

DISTNAME=	nvramtool-${NVRAMTOOL_SNAP_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	#empty

MAINTAINER=	jakllsch@kollasch.net
HOMEPAGE=	http://www.coreboot.org/Nvramtool
COMMENT=	Coreboot CMOS NVRAM manipulation utility

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+= gmake
USE_TOOLS+= date

USE_LANGUAGES+= c

SVN_REPOSITORIES=	nvramtool
SVN_TAG=		{${NVRAMTOOL_TAG}}
SVN_ROOT.nvramtool=	svn://coreboot.org/coreboot/trunk/util/nvramtool
SVN_MODULE.nvramtool=	nvramtool

pre-build:
	${CP} ${FILESDIR}/pio.h ${WRKSRC}

.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64

#Not Tested.
#ONLY_FOR_PLATFORM+=     Linux-*-i386 Linux-*-x86_64

.include "../../wip/mk/svn-package.mk"

WRKSRC=			${WRKDIR}/${PKGBASE}

.if ${OPSYS} == "NetBSD"
MAKE_FLAGS+=    LDFLAGS=-l${MACHINE_ARCH}
.endif

BUILD_TARGET= nvramtool

YESTERDAY!=	expr `date +%s` - 86399
NVRAMTOOL_TAG!=		${DATE} +%Y%m%d
NVRAMTOOL_SNAP_VERSION!=		${DATE} -r ${YESTERDAY} +%Y%m%d

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nvramtool ${DESTDIR}${PREFIX}/sbin/nvramtool
	${INSTALL_MAN} ${WRKSRC}/nvramtool.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/nvramtool.8

.include "../../mk/bsd.pkg.mk"
