# $NetBSD: Makefile,v 1.2 2015/01/10 20:48:35 thomasklausner Exp $

PKGNAME=	suse_libgpg-error-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libgpg-error0-1.10-2.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libgpg-error

EMUL_MODULES.linux=	openssl

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
