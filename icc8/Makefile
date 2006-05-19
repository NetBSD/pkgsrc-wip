# $NetBSD: Makefile,v 1.4 2006/05/19 16:51:19 ykomatsu Exp $

DISTNAME=	l_cc_p_8.0.055
PKGNAME=	icc-8.0
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.intel.com/software/products/compilers/downloads/ \
		ftp://download.intel.com/software/products/compilers/downloads/ \
		ftp://download.intel.com/software/products/compilers/downloads/ \
		ftp://download.intel.com/software/products/compilers/downloads/ \
		ftp://download.intel.co.jp/software/products/compilers/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.intel.com/cd/software/products/asmo-na/eng/compilers/
COMMENT=	Intel C++ Compiler for Linux

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH}=="ia64"
LINUX_BINPKG_FILES=	intel-icc8-8.0-44.${LINUX_ARCH_REQD}.rpm \
			intel-eidb7-7.3.1-85.${LINUX_ARCH_REQD}.rpm \
			intel-isubh8-8.0-44.${LINUX_ARCH_REQD}.rpm
.else
.if ${MACHINE_ARCH}=="i386"
LINUX_BINPKG_FILES=	intel-icc8-8.0-44.${LINUX_ARCH_REQD}.rpm \
			intel-iidb7-7.3.1-85.${LINUX_ARCH_REQD}.rpm \
			intel-isubh8-8.0-44.${LINUX_ARCH_REQD}.rpm
.else
.error "This is unavailable for your machine!"
.endif
.endif

.include "../../wip/mk/linuxbin.pkg.mk"
.include "../../mk/bsd.pkg.mk"
