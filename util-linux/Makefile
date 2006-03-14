# $NetBSD: Makefile,v 1.10 2006/03/14 01:28:18 jlamwww Exp $

DISTNAME=	util-linux-2.12r
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/misc/} \
		http://www.kernel.org/pub/linux/utils/util-linux/ \
		ftp://ftp.fr.kernel.org/pub/linux/utils/util-linux/ \
		ftp://ftp.cn.kernel.org/pub/linux/utils/util-linux/ \
		ftp://ftp.win.tue.nl/pub/linux-local/utils/util-linux/
# old: ftp://ftp.cwi.nl/pub/aeb/util-linux/
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
#HOMEPAGE
COMMENT=	Miscellaneous essential utilities for Linux systems

ONLY_FOR_PLATFORM=	Linux-*-* # Uses Linux kernel headers

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
MAKE_ENV+=		DESTDIR=${PREFIX:Q}
MAKE_ENV+=		ETCDIR=${PREFIX:Q}/share/examples/util-linux
MAKE_ENV+=		FDPRMFILE=${PKG_SYSCONFDIR:Q}/fdprm
MAKE_ENV+=		INFO_DIR=/${INFO_DIR:Q}
MAKE_ENV+=		MAN_DIR=/${PKGMANDIR:Q}

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
