# $NetBSD$

PKGVER=		3.0.0-4.4
PKGNAME=	suse_fpc-${PKGVER}-${SUSE_VERSION}
DISTNAME=	fpc-${PKGVER}.${SUSE_ARCH}.rpm
CATEGORIES=	emulators

EXTRACT_SUFX=	# none

MASTER_SITES=	http://packman.jacobs-university.de/suse/${SUSE_VERSION}/Multimedia/${SUSE_ARCH}/ \
		http://packman.inode.at/suse/${SUSE_VERSION}/Multimedia/${SUSE_ARCH}/ \
		ftp://packman.inode.at/suse/${SUSE_VERSION}/Multimedia/${SUSE_ARCH}/ \
		http://ftp.halifax.rwth-aachen.de/packman/suse/${SUSE_VERSION}/Multimedia/${SUSE_ARCH}/ \
		http://ftp.yzu.edu.tw/Linux/packman/suse/${SUSE_VERSION}/Multimedia/${SUSE_ARCH}/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Free Pascal Compiler

EMUL_MODULES.linux=	base binutils

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
