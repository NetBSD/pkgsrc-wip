# $NetBSD: Makefile,v 1.1.1.1 2004/01/27 18:08:12 jeremy-c-reed Exp $

DISTNAME=		iptables-1.2.8
CATEGORIES=		security
MASTER_SITES=		http://www.netfilter.org/files/
MASTER_SITES+=		ftp://ftp.netfilter.org/pub/iptables/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.netfilter.org/
COMMENT=		Interface to Linux netfilter firewalling subsystem

# This package requires a Linux 2.4.4 kernel, or above.
ONLY_FOR_PLATFORM=	Linux-[2-9]*-*

USE_GNU_TOOLS+=		make
NO_CONFIGURE=		YES

do-build:
	cd ${WRKSRC} && \
	${GMAKE} BINDIR=${LOCALBASE}/bin LIBDIR=${LOCALBASE}/lib \
		MANDIR=${LOCALBASE}/man \
 KERNEL_DIR=/tmp/pkgsrc/new/linux-kernel/work.k3/linux-2.4.22/

do-install:
	cd ${WRKSRC} && \
	${GMAKE} BINDIR=${LOCALBASE}/bin LIBDIR=${LOCALBASE}/lib \
		MANDIR=${LOCALBASE}/man install \
 KERNEL_DIR=/tmp/pkgsrc/new/linux-kernel/work.k3/linux-2.4.22/

# If you are a developer, you can install the headers, development libraries
# and associated development man pages, with:
# make install-devel

# If you want to build a statically linked version of the iptables binary,
# without the need for loading the plugins at runtime (e.g. for an embedded
# device or router-on-a-disk), please use
# make NO_SHARED_LIBS=1

.include "../../mk/bsd.pkg.mk"
