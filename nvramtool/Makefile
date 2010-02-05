# $NetBSD: Makefile,v 1.4 2010/02/05 21:01:56 jakllsch Exp $
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nvramtool ${PREFIX}/sbin/nvramtool
	${INSTALL_MAN} ${WRKSRC}/nvramtool.8 ${PREFIX}/${PKGMANDIR}/man8/nvramtool.8

.include "../../mk/bsd.pkg.mk"
