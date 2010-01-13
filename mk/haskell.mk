# $NetBSD: haskell.mk,v 1.15 2010/01/13 02:36:45 phonohawk Exp $
#
# This Makefile fragment handles Haskell Cabal packages.
# See: http://www.haskell.org/cabal/
#
# Note to users:
#
#   * Users choose one favourite Haskell compiler. Though the only
#     compiler currently supported is GHC.
#
#   * You can't install a cabal package for more than one compilers
#     simultaneously. In the future, this limitation can possibly be
#     eliminated using the method used by
#     "../../lang/python/pyversion.mk".
#
# Note to package developers:
#
#   * This file must be included *before* "../../mk/bsd.pkg.mk", or
#     you'll get target-redefinition errors.
#
#   * PKGNAME will automatically be "hs-${DISTNAME}" unless you
#     explicitly declare it.
# 
#   * If your package is on the HackageDB, MASTER_SITES and HOMEPAGE
#     can be omitted.
#
#   * Package configuration, building, installation, registration and
#     unregistration are fully automated. You usually don't need to do
#     anything special.
#
#   * When Haskell libraries depend on other Haskell libraries, they
#     MUST depend on, not build-depend on, such libraries. So if your
#     package installs a library, you MUST NOT set
#     BUILDLINK_DEPMETHOD.${PKG} to "build" in your buildlink3.mk
#     file. Reason:
#         1. Assume we have two libraries A and B, and B build-depends
#            on A.
#         2. We install package A.
#         3. We then install package B, which build-depends on A.
#         4. After that, a new upstream version of package A is
#            released. We therefore update package A to the new version.
#         5. Package B had a build-dependency on A, so pkgsrc assumes
#            that it's still safe to use package B without
#            recompilation of B. But in fact package B requires the
#            very version of package A which was available when
#            package B was compiled. So the installed package B is
#            completely broken at this time.
#
# Public variables for users:
#
#   HASKELL_COMPILER
#       Description:
#           The user's favourite Haskell compiler.
#       Possible values:
#           ghc
#       Default value:
#           ghc
#
# Public variables for packages:
#
#   HASKELL_ENABLE_LIBRARY_PROFILING
#       Description:
#           Whether profiling library should be built or not.
#       Possible values:
#           yes, no
#       Default value:
#           yes
#
#    HASKELL_ENABLE_HADDOCK_DOCUMENTATION
#        Description:
#            Whether haddock documentation should be built or not.
#        Possible values:
#            yes, no
#        Default value:
#            no

.if !defined(HASKELL_MK)
HASKELL_MK=	# defined


# -----------------------------------------------------------------------------
# This declaration should be placed in ../../mk/fetch/sites.mk
#
MASTER_SITE_HASKELL_HACKAGE?=	http://hackage.haskell.org/packages/archive/
# -----------------------------------------------------------------------------


# -----------------------------------------------------------------------------
# This declaration should be placed in ../../mk/defaults/mk.conf
#
HASKELL_COMPILER?=	ghc
# Used by haskell.mk to determine which Haskell compiler should be
# used for building Haskell packages.
# Possible: ghc
# Default: ghc
# -----------------------------------------------------------------------------


# To be deprecated: if HASKELL_TYPE is set, copy its value to
# HASKELL_COMPILER. The former is an old variable name of the latter.
.if defined(HASKELL_TYPE)
HASKELL_COMPILER?=	${HASKELL_TYPE}
.endif


# Declare HASKELL_COMPILER as one of BUILD_DEFS variables. See
# ../../mk/misc/show.mk
BUILD_DEFS+=	HASKELL_COMPILER


# Cabal packages usually support DESTDIR with no root access.
PKG_DESTDIR_SUPPORT?=	user-destdir


# Declarations for ../../mk/misc/show.mk
_VARGROUPS+=		haskell
_DEF_VARS.haskell= \
	_CABAL_SETUP_SCRIPT \
	_DISTBASE \
	_DISTVERSION \
	_GHC_BIN \
	_GHC_PKG_BIN \
	_GHC_VERSION \
	_GHC_VERSION_CMD \
	_GHC_VERSION_FULL \
	_HASKELL_PKG_BIN \
	_HASKELL_PKG_DESCR_FILE \
	_HASKELL_VERSION \
	_RUNHASKELL_BIN \
	_RUNGHC_BIN
_PKG_VARS.haskell= \
	HASKELL_ENABLE_LIBRARY_PROFILING

# PKGNAME is usually named after DISTNAME.
PKGNAME?=	hs-${DISTNAME}

# Default value of MASTER_SITES.
_DISTBASE?=	${DISTNAME:C/-[^-]*$//}
_DISTVERSION?=	${DISTNAME:C/^.*-//}
MASTER_SITES?=	${MASTER_SITE_HASKELL_HACKAGE:=${_DISTBASE}/${_DISTVERSION}/}

# Default value of HOMEPAGE.
HOMEPAGE?=	http://hackage.haskell.org/cgi-bin/hackage-scripts/package/${_DISTBASE}

# Cabal packages may use pkg-config, but url2pkg can't detect
# that. (PHO: I think that should be handled by url2pkg (2009-05-20))
USE_TOOLS+=	pkg-config

# Default value of HASKELL_ENABLE_LIBRARY_PROFILING
HASKELL_ENABLE_LIBRARY_PROFILING?=	yes

# Default value of HASKELL_ENABLE_HADDOCK_DOCUMENTATION
HASKELL_ENABLE_HADDOCK_DOCUMENTATION?=	no

# Compiler specific variables and targets.
.if ${HASKELL_COMPILER} == "ghc"

# Add dependency to the GHC.
.include "../../wip/ghc/buildlink3.mk"

# Tools
_GHC_BIN=		${PREFIX}/bin/ghc
_GHC_PKG_BIN=		${PREFIX}/bin/ghc-pkg
_RUNGHC_BIN=		${PREFIX}/bin/runghc
_HASKELL_PKG_BIN=	${_GHC_PKG_BIN} # Expose to the outer scope.
_RUNHASKELL_BIN=	${_RUNGHC_BIN}  # ditto

# Determine GHC version.
_GHC_VERSION_CMD=	${_GHC_BIN} -V | ${CUT} -d ' ' -f 8
_GHC_VERSION=		${_GHC_VERSION_CMD:sh}
_GHC_VERSION_FULL=	ghc-${_GHC_VERSION}
_HASKELL_VERSION=	${_GHC_VERSION_FULL} # Expose to the outer scope.

# GHC requires C compiler.
USE_LANGUAGES+=	c

# Declarations for ../../mk/configure/configure.mk
CONFIGURE_ARGS+=	--ghc
CONFIGURE_ARGS+=	--with-compiler=${_GHC_BIN}
CONFIGURE_ARGS+=	--with-hc-pkg=${_GHC_PKG_BIN}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
.endif # ${HASKELL_COMPILER}

# Library profiling
PLIST_VARS+=		prof
.if ${HASKELL_ENABLE_LIBRARY_PROFILING} == "yes"
CONFIGURE_ARGS+=	-p
PLIST.prof=		yes
.endif


# Haddock documentations
PLIST_VARS+=		doc
.if ${HASKELL_ENABLE_HADDOCK_DOCUMENTATION} == "yes"
.include "../../wip/hs-haddock/buildlink3.mk"
CONFIGURE_ARGS+=	--with-haddock=${PREFIX}/bin/haddock
PLIST.doc=		yes
.endif

# Optimization
CONFIGURE_ARGS+=	-O2

# package.conf and package.conf.old should be ignored at all.
PRINT_PLIST_AWK+= \
	/\/package\.conf(\.old)?$$/ { next; } \
	/^@dirrm lib\/${_HASKELL_VERSION}$$/ { next; }

# _HASKELL_VERSION should be substituted in PLIST.
PLIST_SUBST+=	HASKELL_VERSION=${_HASKELL_VERSION}
PRINT_PLIST_AWK+= \
	{ gsub(/${_HASKELL_VERSION}/, "$${HASKELL_VERSION}"); }

# Setup script can either be Setup.hs or Setup.lhs.
_CABAL_SETUP_SCRIPT=	Setup.*hs

# Define configure target.
do-configure:
	${RUN} cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
			${_RUNHASKELL_BIN} ${_CABAL_SETUP_SCRIPT} configure ${CONFIGURE_ARGS}

# Define build target.
do-build:
	${RUN} cd ${WRKSRC} && \
		${_RUNHASKELL_BIN} ${_CABAL_SETUP_SCRIPT} build
.if ${HASKELL_ENABLE_HADDOCK_DOCUMENTATION} == "yes"
	${RUN} cd ${WRKSRC} && \
		${_RUNHASKELL_BIN} ${_CABAL_SETUP_SCRIPT} haddock
.endif

# Define install target. We need installed-pkg-config to be installed
# for package registration (if any).
_HASKELL_PKG_DESCR_FILE=	${PREFIX}/lib/${DISTNAME}/${_HASKELL_VERSION}/package-description

do-install:
	${RUN} cd ${WRKSRC} && \
		${_RUNHASKELL_BIN} ${_CABAL_SETUP_SCRIPT} register --gen-pkg-config=dist/package-description && \
		if [ "${DESTDIR}" = "" ]; then \
			${_RUNHASKELL_BIN} ${_CABAL_SETUP_SCRIPT} copy && \
			if [ -f dist/package-description ]; then \
				${INSTALL_DATA} dist/package-description ${_HASKELL_PKG_DESCR_FILE}; \
			fi \
		else \
			${_RUNHASKELL_BIN} ${_CABAL_SETUP_SCRIPT} copy --destdir=${DESTDIR} && \
			if [ -f dist/package-description ]; then \
				${INSTALL_DATA} dist/package-description ${DESTDIR}${_HASKELL_PKG_DESCR_FILE}; \
			fi \
		fi

# Substitutions for INSTALL and DEINSTALL.
FILES_SUBST+=	DISTNAME=${DISTNAME}
FILES_SUBST+=	HASKELL_PKG_BIN=${_HASKELL_PKG_BIN}
FILES_SUBST+=	HASKELL_PKG_DESCR_FILE=${_HASKELL_PKG_DESCR_FILE}

# INSTALL_TEMPLATES+=	../../mk/haskell/INSTALL.in
# DEINSTALL_TEMPLATES+=	../../mk/haskell/DEINSTALL.in
INSTALL_TEMPLATES+=	../../wip/mk/haskell/INSTALL.in
DEINSTALL_TEMPLATES+=	../../wip/mk/haskell/DEINSTALL.in


.endif # HASKELL_MK
