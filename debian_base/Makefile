# $Id: Makefile,v 1.1.1.1 2004/06/11 09:59:39 grantbeattie Exp $

DISTNAME=		# empty
DISTFILES=		${DEBS}
PKGNAME=		debian_base-3.1
CATEGORIES=		emulators
MASTER_SITES=		http://ftp.wa.au.debian.org/debian/pool/main/g/glibc/
MASTER_SITES+=		http://ftp.wa.au.debian.org/debian/pool/main/z/zlib/
MASTER_SITES+=		http://ftp.wa.au.debian.org/debian/pool/main/g/gcc-3.3/

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.debian.org/
COMMENT=		Debian Linux compatibility base package

# these are from the latest unstable packages in /debian/pool/main/
# dated 20040607.
DEBS+=			libc6_2.3.2.ds1-13_${MACHINE_ARCH}.deb
DEBS+=			zlib1g_1.2.1.1-3_${MACHINE_ARCH}.deb
DEBS+=			libstdc++5_3.3.3-9_${MACHINE_ARCH}.deb

do-extract:		do-extract-deb
do-install:		do-install-deb

.include "../../wip/debian_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
