# $NetBSD: Makefile,v 1.5 2005/05/24 10:30:23 rillig Exp $

DISTNAME=		iptables-1.3.0
CATEGORIES=		security
MASTER_SITES=		http://www.netfilter.org/files/
MASTER_SITES+=		ftp://ftp.netfilter.org/pub/iptables/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.netfilter.org/
COMMENT=		Interface to Linux netfilter firewalling subsystem

# This package requires a Linux 2.4.4 kernel, or above.
ONLY_FOR_PLATFORM=	Linux-[2-9]*-*

USE_TOOLS+=		gmake
NO_CONFIGURE=		YES
PKGMANDIR?=		man  # until this in official pkgsrc

do-build:
	cd ${WRKSRC} && \
	${GMAKE} BINDIR=${LOCALBASE}/bin LIBDIR=${LOCALBASE}/lib \
		MANDIR=${LOCALBASE}/${PKGMANDIR}

do-install:
	cd ${WRKSRC} && \
	${GMAKE} BINDIR=${LOCALBASE}/bin LIBDIR=${LOCALBASE}/lib \
		MANDIR=${LOCALBASE}/${PKGMANDIR} install

# If you are a developer, you can install the headers, development libraries
# and associated development man pages, with:
# make install-devel

# If you want to build a statically linked version of the iptables binary,
# without the need for loading the plugins at runtime (e.g. for an embedded
# device or router-on-a-disk), please use
# make NO_SHARED_LIBS=1

.include "../../mk/bsd.pkg.mk"
