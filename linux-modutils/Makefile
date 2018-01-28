# $NetBSD: Makefile,v 1.8 2012/10/03 09:10:42 asau Exp $

DISTNAME=		modutils-2.4.24
PKGNAME=		linux-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://ftp.kernel.org/pub/linux/utils/kernel/modutils/v2.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.kernel.org/
COMMENT=		Linux kernel module utilities

CONFLICTS+=		linux-module-init-tools-[0-9]*

ONLY_FOR_PLATFORM=	Linux-*-* # This is for the Linux kernel


GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX} --sysconfdir=${PKG_SYSCONFDIR}
USE_TOOLS+=		gmake

RCD_SCRIPTS=		modutils

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/linux-modutils
	${INSTALL_DATA} ${WRKSRC}/depmod/Example.modules.conf ${PREFIX}/share/linux-modutils/modules.conf.example

.include "../../mk/bsd.pkg.mk"
