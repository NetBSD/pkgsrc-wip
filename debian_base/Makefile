# $NetBSD: Makefile,v 1.6 2012/09/28 21:24:31 asau Exp $
# $Id: Makefile,v 1.6 2012/09/28 21:24:31 asau Exp $

DISTNAME=		# empty
DISTFILES=		${DEBS}
PKGNAME=		debian_base-3.1
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		# none

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.debian.org/
COMMENT=		Debian Linux compatibility base package

# Last updated: 2005-11-03.
DISTFILE_LIBC=			libc6_2.3.2.ds1-22_${MACHINE_ARCH}.deb
SITES.${DISTFILE_LIBC}=		${MASTER_SITE_DEBIAN:=pool/main/g/glibc/}
DEBS+=				${DISTFILE_LIBC}
DISTFILE_ZLIB=			zlib1g_1.2.3-6_${MACHINE_ARCH}.deb
SITES.${DISTFILE_ZLIB}=		${MASTER_SITE_DEBIAN:=pool/main/z/zlib/}
DEBS+=				${DISTFILE_ZLIB}
DISTFILE_LIBSTDCXX=		libstdc++5_3.3.6-7_${MACHINE_ARCH}.deb
SITES.${DISTFILE_LIBSTDCXX}=	${MASTER_SITE_DEBIAN:=pool/main/g/gcc-3.3/}
DEBS+=				${DISTFILE_LIBSTDCXX}


do-extract:		do-extract-deb
do-install:		do-install-deb

.include "../../wip/debian_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
