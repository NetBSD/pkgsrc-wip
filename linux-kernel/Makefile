# $NetBSD: Makefile,v 1.1.1.1 2004/01/27 17:51:08 jeremy-c-reed Exp $

LINUX_VERSION=		2.4.22
DISTNAME=		linux-${LINUX_VERSION}
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.kernel.org/pub/linux/kernel/v2.4/ \
			http://www.de.kernel.org/pub/linux/kernel/v2.4/ \
			ftp://ftp.jp.kernel.org/pub/linux/kernel/v2.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.kernel.org/
COMMENT=		The Linux kernel

BUILD_DEPENDS+=		linux-modutils-[0-9]*:../../wip/linux-modutils

PLIST_SUBST+=           LINUX_VERSION=${LINUX_VERSION}

USE_GNU_TOOLS+=		make

do-configure:
	cd ${WRKSRC} && \
	yes "" | ${GMAKE} config && \
	${CAT} ${FILESDIR}/extra-configs >> .config && \
	yes "" | ${GMAKE} oldconfig # regenerate config after appending to it

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} dep

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} bzImage && \
	${SETENV} ${MAKE_ENV} ${GMAKE} modules

do-install:
	${CP} ${WRKSRC}/arch/${LOWER_ARCH}/boot/bzImage /boot/bzImage-${LINUX_VERSION}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} modules_install

.include "../../mk/bsd.pkg.mk"

CC=	${LOCALBASE}/gcc3/bin/gcc
