# $NetBSD: haskell.mk,v 1.2 2008/07/20 05:56:00 phonohawk Exp $
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
#     simultaneously. This limitation can possibly be eliminated using
#     package-options-framework in the future.
#
# Note to package developers:
#
#   * This file must be included *before* "../../mk/bsd.pkg.mk", or
#     you'll get target-redefinition errors.
# 
#   * If your package is on the HackageDB, MASTER_SITES should be
#     expressed like this:
#
#       MASTER_SITES= ${MASTER_SITE_HASKELL_HACKAGE:=FooBar/0.1.2/}
#
#     where "FooBar" is the name of package and "0.1.2" is the version
#     number. Don't forget the trailing slash.
#
#   * Package configuration, building, installation, registration and
#     unregistration are fully automated. You usually don't need to do
#     anything special.
#
# Public variables for users:
#
#   HASKELL_TYPE
#       Description:
#           The user's favourite Haskell compiler.
#       Possible values:
#           ghc
#       Default value:
#           ghc
#
# Public variables for packages:
#
#   (nothing currently)
#

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
HASKELL_TYPE?=	ghc
# Used by haskell.mk to determine which Haskell compiler should be
# used for building Haskell packages.
# Possible: ghc
# Default: ghc
# -----------------------------------------------------------------------------


# Declarations for ../../mk/misc/show.mk
_VARGROUPS+=		haskell
_USER_VARS.haskell=	HASKELL_TYPE
_DEF_VARS.haskell= \
	_CABAL_SETUP_SCRIPT \
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


# Compiler specific variables and targets.
.if ${HASKELL_TYPE} == "ghc"

# Add dependency to the GHC.
.include "../../lang/ghc/buildlink3.mk"

# Tools
_GHC_BIN=			${PREFIX}/bin/ghc
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

.endif # ${HASKELL_TYPE}

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
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
			${_RUNHASKELL_BIN} ${_CABAL_SETUP_SCRIPT} configure ${CONFIGURE_ARGS}

# Define build target.
do-build:
	cd ${WRKSRC} && \
		${_RUNHASKELL_BIN} ${_CABAL_SETUP_SCRIPT} build

# Define install target. We need installed-pkg-config to be installed
# for package registration.
_HASKELL_PKG_DESCR_FILE=	${PREFIX}/lib/${DISTNAME}/${_HASKELL_VERSION}/package-description
do-install:
	cd ${WRKSRC} && \
		${_RUNHASKELL_BIN} ${_CABAL_SETUP_SCRIPT} copy && \
		${INSTALL_DATA} dist/installed-pkg-config ${_HASKELL_PKG_DESCR_FILE}

# Substitutions for INSTALL and DEINSTALL.
FILES_SUBST+=	DISTNAME=${DISTNAME}
FILES_SUBST+=	HASKELL_PKG_BIN=${_HASKELL_PKG_BIN}
FILES_SUBST+=	HASKELL_PKG_DESCR_FILE=${_HASKELL_PKG_DESCR_FILE}

# INSTALL_TEMPLATES+=	../../mk/haskell/INSTALL.in
# DEINSTALL_TEMPLATES+=	../../mk/haskell/DEINSTALL.in
INSTALL_TEMPLATES+=		../../wip/mk/haskell/INSTALL.in
DEINSTALL_TEMPLATES+=	../../wip/mk/haskell/DEINSTALL.in


.endif # HASKELL_MK