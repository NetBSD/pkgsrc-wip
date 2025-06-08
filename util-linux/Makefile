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

MESON_ARGS+=		-Dbuild-liblastlog2=disabled
MESON_ARGS+=		-Dbuild-login=disabled
MESON_ARGS+=		-Dbuild-chfn-chsh=disabled
MESON_ARGS+=		-Dbuild-su=disabled
MESON_ARGS+=		-Dbuild-runuser=disabled
MESON_ARGS+=		-Dbuild-pg=disabled
MESON_ARGS+=		-Dbuild-more=disabled
MESON_ARGS+=		-Dbuild-ul=disabled
MESON_ARGS+=		-Dbuild-irqtop=disabled
MESON_ARGS+=		-Dbuild-agetty=disabled
MESON_ARGS+=		-Dbuild-fdisks=disabled
MESON_ARGS+=		-Dbuild-sulogin=disabled
MESON_ARGS+=		-Dbuild-setterm=disabled
MESON_ARGS+=		-Dbuild-python=disabled
MESON_ARGS+=		-Dbuild-libmount=disabled
MESON_ARGS+=		-Dbuild-libuuid=disabled

PLIST_SRC=	PLIST

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/getopt

.include "../../devel/meson/build.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
#.include "../../devel/ncurses/buildlink3.mk"
# zlib used for cramfs
.include "../../devel/zlib/buildlink3.mk"
#.include "../../databases/sqlite3/buildlink3.mk"
#.include "../../security/openpam/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
