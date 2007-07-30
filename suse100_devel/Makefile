# $NetBSD: Makefile,v 1.3 2007/07/30 15:49:11 jlamwww Exp $

DISTNAME=		suse_devel-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
DISTFILES=		binutils-2.16.91.0.2-8.2.${SUSE_ARCH}.rpm \
			cpp-4.0.2_20050901-3.${SUSE_ARCH}.rpm \
			gcc-4.0.2_20050901-3.${SUSE_ARCH}.rpm \
			gcc-c++-4.0.2_20050901-3.${SUSE_ARCH}.rpm \
			gcc-fortran-4.0.2_20050901-3.${SUSE_ARCH}.rpm \
			gcc-locale-4.0.2_20050901-3.${SUSE_ARCH}.rpm \
			gcc-mudflap-4.0.2_20050901-3.${SUSE_ARCH}.rpm \
			gcc-objc-4.0.2_20050901-3.${SUSE_ARCH}.rpm \
			glibc-devel-2.3.5-40.${SUSE_ARCH}.rpm \
			gmp-4.1.4-6.${SUSE_ARCH}.rpm \
			libobjc-4.0.2_20050901-3.${SUSE_ARCH}.rpm \
			libstdc++-devel-4.0.2_20050901-3.${SUSE_ARCH}.rpm \
			make-3.80-188.${SUSE_ARCH}.rpm

MAINTAINER=		hauke@NetBSD.org
COMMENT=		Linux compatibility package - development tools

EMUL_MODULES.linux=	base

OWN_DIRS+=		${EMULDIR}/usr/i586-suse-linux/lib

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
