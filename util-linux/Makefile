# $NetBSD: Makefile,v 1.7 2005/05/24 10:31:47 rillig Exp $

# newest version may be util-linux-2.12h but not on mirrors
DISTNAME=	util-linux-2.12b
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.win.tue.nl/pub/linux-local/utils/util-linux/ \
		${MASTER_SITE_SUNSITE:=system/misc/} \
		ftp://ftp.cwi.nl/pub/aeb/util-linux/ \
		http://www.kernel.org/pub/linux/utils/util-linux/ \
		ftp://ftp.fr.kernel.org/pub/linux/utils/util-linux/ \
		ftp://ftp.cn.kernel.org/pub/linux/utils/util-linux/
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
#HOMEPAGE
COMMENT=	Miscellaneous essential utilities for Linux systems

ONLY_FOR_PLATFORM=	Linux-*-* # Uses Linux kernel headers

USE_PKGINSTALL=		YES
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
MAKE_ENV+=		DESTDIR=${PREFIX}
MAKE_ENV+=		ETCDIR=${PREFIX}/share/examples/util-linux
MAKE_ENV+=		FDPRMFILE=${PKG_SYSCONFDIR}/fdprm
MAKE_ENV+=		INFO_DIR=/${INFO_DIR}
PKGMANDIR?=		man
MAKE_ENV+=		MAN_DIR=/${PKGMANDIR}

INFO_FILES=		ipc.info

CONF_FILES=	${PREFIX}/share/examples/util-linux/fdprm ${PKG_SYSCONFDIR}/fdprm

PLIST_SRC=		${PKGDIR}/PLIST
# XXX let maintainer know of your architecture if this breaks
PLIST_SRC+=		${PKGDIR}/PLIST.${MACHINE_ARCH}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
# zlib used for cramfs
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
