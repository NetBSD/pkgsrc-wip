# $NetBSD: Makefile,v 1.2 2004/05/10 23:44:31 jeremy-c-reed Exp $
#

DISTNAME=		module-init-tools-3.0
PKGNAME=		linux-${DISTNAME}
CATEGORIES=		sysutils
MASTER_SITES=		http://www.kernel.org/pub/linux/kernel/people/rusty/modules/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.kernel.org/pub/linux/kernel/people/rusty/modules/
COMMENT=		Linux kernel module utilities (versions 2.5.48 and above)

CONFLICTS+=		linux-modutils-[0-9]*

ONLY_FOR_PLATFORM=	Linux-*-* # configure: error: Linux only, dude!

USE_PKGINSTALL= 	YES

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

RCD_SCRIPTS=		modutils

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/linux-module-init-tools
	${INSTALL_DATA} ${WRKSRC}/modprobe.devfs ${PREFIX}/share/examples/linux-module-init-tools/modprobe.devfs.example

.include "../../mk/bsd.pkg.mk"
