# $NetBSD: Makefile,v 1.6 2008/01/25 21:42:19 asau Exp $

DISTNAME=		${PKGNAME_NOREV}-source
PKGNAME=		sbcl-1.0.13
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sbcl/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@users.sourceforge.net
HOMEPAGE=		http://www.sbcl.org/
COMMENT=		SBCL, a Common Lisp implementation

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386
ONLY_FOR_PLATFORM+=	FreeBSD-[2-9]*-i386
# It should be possible to have SBCL working on amd64, powerpc,
# sparc, alpha, mips, and HPPA hardware also, but they probably
# need a bit of porting work done in SBCL itself.
# In addition, SBCL should also work on Linux, Darwin, Solaris,
# FreeBSD, OpenBSD, and possibly Win32, OSF/1, HP-UX, and Irix.

USE_TOOLS+=		gmake gtar:run
PKG_INSTALLATION_TYPES=	overwrite pkgviews

#USE_CONFIGURE=yes
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}/

.include "../../mk/bsd.prefs.mk"

#
# Bootstrap section.
#
# SBCL needs an existing Common Lisp system to build it...
# Currently allowed systems are CLisp, CMUCL, OpenMCL, and SBCL itself.
#
#  Note that CLisp 2.39nb1 worked two or three times when testing
#  this package and it failed to build SBCL twice.  It is also at
#  least twice as slow as using SBCL when building on an i386 platform.
#
#  I have never been able to get CLisp to build on a SPARC system, so
#  I had to cross build when trying to port SBCL to NetBSD/sparc.
#  I have reports that CLisp will build on PowerPC platforms, but is
#  unable to build SBCL.
#
#  If SBCL is installed in an unusual place when trying to build this
#  package, you may need to set the full path in SBCL_BOOT_SYSTEM and
#  build the package with "SBCL_HOME=/path/to/SBCL/core/image/ make"

#SBCL_BOOT_SYSTEM=	clisp			# CLisp
#SBCL_BOOT_SYSTEM=	"lisp -batch"		# CMUCL
#SBCL_BOOT_SYSTEM=	"openmcl --batch"	# OpenMCL
#SBCL_BOOT_SYSTEM=	sbcl			# SBCL

.if !defined(SBCL_BOOT_SYSTEM)
PKG_FAIL_REASON+=	"Please set SBCL_BOOT_SYSTEM=sbcl in mk.conf"
.elif defined(SBCL_BOOT_SYSTEM) && ${SBCL_BOOT_SYSTEM} == sbcl
# Get bootstrap version:
BUILD_DEPENDS+=		sbcl-[0-9]*:../sbcl-boot
.endif
.if defined(SBCL_BOOT_SYSTEM) && ${SBCL_BOOT_SYSTEM} == clisp
PKG_FAIL_REASON+=	"Sorry, it doesn't work with CLISP."
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
	cd ${WRKSRC} && ${SH} make.sh "${SBCL_BOOT_SYSTEM}"
post-build:
	cd ${WRKSRC} && ${RM} -rf contrib/sb-cover/test-output contrib/sb-cover/tests.fasl contrib/sb-cover/test-data-*.fasl

do-install:
	cd ${WRKSRC} && INSTALL_ROOT=${PREFIX} MAN_DIR=${PREFIX}/${PKGMANDIR} ${SH} install.sh

.include "../../mk/bsd.pkg.mk"
