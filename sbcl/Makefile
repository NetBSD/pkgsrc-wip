# $NetBSD: Makefile,v 1.28 2010/08/28 22:11:54 asau Exp $

DISTNAME=		${PKGNAME_NOREV}-source
PKGNAME=		sbcl-1.0.40
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sbcl/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@users.sourceforge.net
HOMEPAGE=		http://www.sbcl.org/
COMMENT=		SBCL, a Common Lisp implementation

# ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386
# ONLY_FOR_PLATFORM+=	FreeBSD-[2-9]*-i386
# ONLY_FOR_PLATFORM+=	Linux-*-i386
# It should be possible to have SBCL working on amd64, powerpc,
# sparc, alpha, mips, and HPPA hardware also, but they probably
# need a bit of porting work done in SBCL itself.
# In addition, SBCL should also work on Darwin, Solaris, OpenBSD,
# and possibly Win32, OSF/1, HP-UX, and Irix.

USE_TOOLS+=		gmake gtar:run
PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

#USE_CONFIGURE=yes
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

#
# Bootstrap section.
#
# SBCL needs an existing Common Lisp system to build it...
# Currently allowed systems are CLISP, CMUCL, OpenMCL, and SBCL itself.
#
#  If SBCL is installed in an unusual place when trying to build this
#  package, you may need to set the full path in SBCL_BOOT_SYSTEM and
#  build the package with "SBCL_HOME=/path/to/SBCL/core/image/ make"

#SBCL_BOOT_SYSTEM=	clisp			# CLisp
#SBCL_BOOT_SYSTEM=	"lisp -batch"		# CMUCL
#SBCL_BOOT_SYSTEM=	"openmcl --batch"	# OpenMCL
#SBCL_BOOT_SYSTEM=	sbcl			# SBCL

.if !defined(SBCL_BOOT_SYSTEM)
# Use "clisp -ansi -on-error abort" to make the build more reproducible,
# per Christophe Rhodes:
SBCL_BOOT_SYSTEM=	clisp -norc -ansi -on-error abort
BUILD_DEPENDS+=		clisp-[0-9]*:../../lang/clisp
UNLIMIT_RESOURCES=	datasize
.elif ${SBCL_BOOT_SYSTEM} == clisp
BUILD_DEPENDS+=		clisp-[0-9]*:../../lang/clisp
UNLIMIT_RESOURCES=	datasize
.elif ${SBCL_BOOT_SYSTEM} == sbcl
# Get bootstrap version:
BUILD_DEPENDS+=		sbcl-[0-9]*:../../lang/sbcl
.endif


SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		install.sh src/runtime/runtime.c doc/sbcl.1
SUBST_SED.fix-paths=		-e 's,@PREFIX@,${PREFIX},g'
#SUBST_SED.fix-paths+=           -e 's,/var/log,${VARBASE}/log,g'

SUBST_CLASSES+=			fix-gtar
SUBST_STAGE.fix-gtar=		pre-configure
SUBST_MESSAGE.fix-gtar=		Fixing GNU tar references.
SUBST_FILES.fix-gtar=		contrib/asdf-install/installer.lisp
SUBST_SED.fix-gtar=		-e 's,@GTAR@,${GTAR},'

do-build:
	cd ${WRKSRC} && ${SH} make.sh --prefix=${PREFIX} --xc-host=${SBCL_BOOT_SYSTEM:Q}
post-build:
	cd ${WRKSRC} && ${RM} -f contrib/sb-cover/test-output/*

do-install:
	cd ${WRKSRC} && BUILD_ROOT=${DESTDIR:Q} INSTALL_ROOT=${PREFIX:Q} MAN_DIR=${PREFIX:Q}/${PKGMANDIR} ${SH} install.sh
	rm -f $(DESTDIR)$(PREFIX)/lib/sbcl/asdf-install/installer.lisp.orig
	rm -f $(DESTDIR)$(PREFIX)/lib/sbcl/sb-posix/posix-tests.lisp.orig
	find $(DESTDIR)$(PREFIX)/lib/sbcl -type d -name CVS -exec rm -rf {} \+

do-test:
	cd ${WRKSRC}/tests && ${SH} ./run-tests.sh

.if $(LOWER_ARCH) == "amd64" || $(LOWER_ARCH) == "x86_64"
PLIST_SUBST+=	SUFX64=-64
.else
PLIST_SUBST+=	SUFX64=
.endif


CVS_REPOSITORIES=	sbcl
CVS_ROOT.sbcl=		:pserver:anonymous:@sbcl.cvs.sourceforge.net:/cvsroot/sbcl
WRKSRC=			${WRKDIR}/sbcl
DISTNAME=
PKGNAME=		sbcl-1.0.99

.include "../mk/cvs-package.mk"

.include "../../mk/bsd.pkg.mk"
