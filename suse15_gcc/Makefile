# $NetBSD$

PKGNAME=	suse_gcc-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	gcc12-12.2.1+git416-150000.1.7.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for GNU GCC

EMUL_MODULES.linux=	base binutils

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
