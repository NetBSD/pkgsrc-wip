# $NetBSD: Makefile,v 1.1.1.1 2003/10/01 22:53:38 jeremy-c-reed Exp $

DISTNAME=	util-linux-2.11z
CATEGORIES=	sysutils
MASTER_SITES=	http://www.kernel.org/pub/linux/utils/util-linux/ \
		ftp://ftp.fr.kernel.org/pub/linux/utils/util-linux/ \
		ftp://ftp.cn.kernel.org/pub/linux/utils/util-linux/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
#HOMEPAGE
COMMENT=	Miscellaneous essential utilities for Linux systems

ONLY_FOR_PLATFORM=	Linux-*-* # Uses Linux kernel headers

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
MAKE_ENV+=	DESTDIR=${PREFIX}
MAKE_ENV+=	ETCDIR=${PREFIX}/share/examples/util-linux
MAKE_ENV+=	FDPRMFILE=${PKG_SYSCONFDIR}/fdprm

INFO_FILES=	ipc.info

CONF_FILES=	${PREFIX}/share/examples/util-linux/fdprm ${PKG_SYSCONFDIR}/fdprm

#.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
# zlib used for cramfs
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
