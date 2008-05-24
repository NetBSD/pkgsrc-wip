# $NetBSD: Makefile,v 1.2 2008/05/24 15:34:11 tnn2 Exp $
#

DISTNAME=	lxbios-${LXBIOS_SNAP_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	#empty

MAINTAINER=	jakllsch@kollasch.net
HOMEPAGE=	http://linuxbios.org/Lxbios
COMMENT=	LinuxBIOS CMOS NVRAM manipulation utility

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+= gmake
USE_TOOLS+= date

USE_LANGUAGES+= c

SVN_REPOSITORIES=	lxbios
SVN_TAG=		{${LXBIOS_TAG}}
SVN_ROOT.lxbios=	svn://linuxbios.org/repos/trunk/util/lxbios
SVN_MODULE.lxbios=	lxbios

pre-build:
	${CP} ${FILESDIR}/pio.h ${WRKSRC}

.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64

#Not Tested.
#ONLY_FOR_PLATFORM+=     Linux-*-i386 Linux-*-x86_64

.include "../../wip/mk/svn-package.mk"

WRKSRC=			${WRKDIR}/${PKGBASE}

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+= iopl
SUBST_FILES.iopl+=	cmos_lowlevel.c
SUBST_MESSAGE.iopl=	fixing iopl
SUBST_STAGE.iopl=	pre-configure
SUBST_SED.iopl+= -e 's,i386_iopl,${MACHINE_ARCH}_iopl,g'

MAKE_ENV+=	LDLIBS=-l${MACHINE_ARCH}

.endif

BUILD_TARGET= lxbios

YESTERDAY!=	expr `date +%s` - 86399
LXBIOS_TAG!=		${DATE} +%Y%m%d
LXBIOS_SNAP_VERSION!=		${DATE} -r ${YESTERDAY} +%Y%m%d

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lxbios ${PREFIX}/sbin/lxbios
	${INSTALL_MAN} ${WRKSRC}/lxbios.1 ${PREFIX}/${PKGMANDIR}/man8/lxbios.8

.include "../../mk/bsd.pkg.mk"
