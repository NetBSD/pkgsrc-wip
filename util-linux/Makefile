# $NetBSD: Makefile,v 1.13 2012/10/07 17:41:40 asau Exp $

DISTNAME=	util-linux-2.40.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/misc/} \
		http://www.kernel.org/pub/linux/utils/util-linux/v2.40/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
#HOMEPAGE
COMMENT=	Miscellaneous essential utilities for Linux systems

CONFLICTS=	ddate-[0-9]*

ONLY_FOR_PLATFORM=	Linux-*-* # Uses Linux kernel headers
CHECK_PORTABILITY_SKIP=	tools/config-gen

#USE_TOOLS+=		gmake
#GNU_CONFIGURE=		YES
MAKE_ENV+=		DESTDIR=${PREFIX}
MAKE_ENV+=		ETCDIR=${PREFIX}/share/examples/util-linux
MAKE_ENV+=		FDPRMFILE=${PKG_SYSCONFDIR}/fdprm
MAKE_ENV+=		INFO_DIR=/${PKGINFODIR}
MAKE_ENV+=		MAN_DIR=/${PKGMANDIR}

INFO_FILES=		# PLIST

CONF_FILES=	${PREFIX}/share/examples/util-linux/fdprm ${PKG_SYSCONFDIR}/fdprm

PLIST_SRC=		${PKGDIR}/PLIST
# XXX let maintainer know of your architecture if this breaks
PLIST_SRC+=		${PKGDIR}/PLIST.${MACHINE_ARCH}

.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
# zlib used for cramfs
.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
