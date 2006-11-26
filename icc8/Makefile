# $NetBSD: Makefile,v 1.6 2006/11/26 16:43:45 rillig Exp $

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

ONLY_FOR_PLATFORM=	*-*-ia64 *-*-i386

CHECK_PORTABILITY_SKIP=		install.sh
CHECK_INTERPRETER_SKIP=		emul/linux/*

.include "../../mk/bsd.prefs.mk"

LINUX_BASE_NODEPS=	yes
.if ${MACHINE_ARCH}=="ia64"
LINUX_BINPKG_FILES=	intel-icc8-8.0-44.${LINUX_ARCH_REQD}.rpm \
			intel-eidb7-7.3.1-85.${LINUX_ARCH_REQD}.rpm \
			intel-isubh8-8.0-44.${LINUX_ARCH_REQD}.rpm
.elif ${MACHINE_ARCH}=="i386"
LINUX_BINPKG_FILES=	intel-icc8-8.0-44.${LINUX_ARCH_REQD}.rpm \
			intel-iidb7-7.3.1-85.${LINUX_ARCH_REQD}.rpm \
			intel-isubh8-8.0-44.${LINUX_ARCH_REQD}.rpm
.endif

USE_TOOLS+=		bash:run
INSTALLDIR=		${PREFIX}/${EMULSUBDIR}/opt/intel_cc_80
SUBST_CLASSES+=		i
SUBST_STAGE.i=		post-install
SUBST_FILES.i=		${INSTALLDIR}/bin/icc
SUBST_SED.i=		-e 's,<INSTALLDIR>,${INSTALLDIR},g'
SUBST_SED.i+=		-e 's,/bin/sh,${BASH},'

.include "../../wip/mk/linuxbin.pkg.mk"
.include "../../mk/bsd.pkg.mk"
