# $NetBSD: Makefile,v 1.4 2005/05/24 10:30:43 rillig Exp $

DISTNAME=		modutils-2.4.24
PKGNAME=		linux-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.kernel.org/pub/linux/utils/kernel/modutils/v2.4/ \
			http://www.br.kernel.org/pub/linux/utils/kernel/modutils/v2.4/ \
			ftp://ftp.cn.kernel.org/pub/linux/utils/kernel/modutils/v2.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.kernel.org/
COMMENT=		Linux kernel module utilities

CONFLICTS+=		linux-module-init-tools-[0-9]*

USE_PKGINSTALL=		YES

ONLY_FOR_PLATFORM=      Linux-*-* # This is for the Linux kernel

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX} --sysconfdir=${PKG_SYSCONFDIR}
USE_TOOLS+=		gmake

RCD_SCRIPTS=		modutils

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/linux-modutils
	${INSTALL_DATA} ${WRKSRC}/depmod/Example.modules.conf ${PREFIX}/share/linux-modutils/modules.conf.example

.include "../../mk/bsd.pkg.mk"
