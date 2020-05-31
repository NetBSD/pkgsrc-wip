# $NetBSD$
#
# This file provides simple access to Fossil repositories, so that packages
# can be created from Fossil instead of from released tarballs. Whenever a
# repository is fetched from Fossil, a copy of it is saved below ${DISTDIR},
# to save bandwidth.
#
# User-settable variables:
#
# CHECKOUT_DATE (optional)
#	Date to check out in ISO format (YYYY-MM-DD).
#
#	When a package doesn't specify a FOSSIL_VERSION, the latest commit
#	is used, and the PKGREVISION is set based on the current date.
#	To keep this date stable during a bulk build (which may span
#	one or more midnights), this can be set to a fixed date.
#
# Package-settable variables:
#
# FOSSIL_REPO (required)
#	The URL of the Fossil repository.
#
#	If the package needs more than one repository, see
#	FOSSIL_REPOSITORIES below.
#
# FOSSIL_EXTRACTDIR (optional)
#	The directory where the files are extracted, relative to WRKDIR.
#
#	Default: ${DISTNAME} without the version number
#
# FOSSIL_VERSION (optional)
#	The revision, tag, date or branch to check out.
#
#	Default: --latest
#
# FOSSIL_REPOSITORIES (optional)
#	If the package needs multiple Fossil repositories, this
#	is the list of repository IDs. For each of these repositories,
#	parameterized variants of the above variables are defined.
#
#	The default value for FOSSIL_EXTRACTDIR.${repo} is ${repo},
#	the repository ID.
#
#	Example:
#	FOSSIL_REPOSITORIES=	stable latest
#	FOSSIL_REPO.stable=	http://core.tcl.tk/tcl/
#	FOSSIL_VERSION.stable=	v1.2.3
#	FOSSIL_REPO.latest=	http://core.tcl.tk/tcl/
#
# Variables set by this file:
#
# DISTFILES
#	Defaults to an empty list.
#	This means that MASTER_SITES does not need to be defined.
#
# PKGREVISION
#	If the package doesn't set a specific FOSSIL_VERSION, this defaults
#	to today in the format yyyymmdd, e.g. 20180225.
#	This keeps the packages distinguishable since the HEAD might
#	change anytime.
#
# Keywords: fossil

BUILD_DEPENDS+=		fossil-[0-9]*:../../devel/fossil

DISTFILES?=		# empty
.if defined(CHECKOUT_DATE)
PKGREVISION?=		${CHECKOUT_DATE:S/-//g}
FOSSIL_VERSION?=	${CHECKOUT_DATE}
.else
PKGREVISION?=		${${DATE} -u +'%Y%m%d':L:sh}
.endif

.if defined(FOSSIL_REPO)
FOSSIL_REPOSITORIES+=		default
FOSSIL_REPO.default=		${FOSSIL_REPO}
FOSSIL_EXTRACTDIR.default=	${DISTNAME:U${PKGNAME}:C,-[0-9].*,,}
.  if defined(FOSSIL_VERSION)
FOSSIL_VERSION.default=		${FOSSIL_VERSION}
.  endif
WRKSRC?=			${WRKDIR}/${FOSSIL_EXTRACTDIR.default}
.endif

FOSSIL_REPOSITORIES?=	# none
.if empty(FOSSIL_REPOSITORIES)
PKG_FAIL_REASON+=	"[fossil-package.mk] FOSSIL_REPOSITORIES must be set."
.endif

.for repo in ${FOSSIL_REPOSITORIES}
.  if empty(FOSSIL_REPO.${repo})
PKG_FAIL_REASON+=	"[fossil-package.mk] FOSSIL_REPO."${repo:Q}" must be set."
.  endif
.  for varbase in FOSSIL_BRANCH FOSSIL_REVISION FOSSIL_TAG # To be removed after 2019-01-01
.    if defined(${varbase}.${repo})
WARNINGS+=		"[fossil-package.mk] ${varbase}.* is obsolete; use FOSSIL_VERSION.${repo} instead."
FOSSIL_VERSION.${repo}?= ${${varbase}.${repo}}
.    endif
.  endfor
.  for varbase in FOSSIL_ENV # To be removed after 2019-01-01
.    if defined(${varbase}.${repo})
WARNINGS+=		"[fossil-package.mk] ${varbase}.* is obsolete."
.    endif
.  endfor
.endfor

USE_TOOLS+=		date pax

_FOSSIL_CMD=		${PREFIX}/bin/fossil
_FOSSIL_DISTDIR=	${DISTDIR}/fossil-packages

.for repo in ${FOSSIL_REPOSITORIES}
FOSSIL_EXTRACTDIR.${repo}?=	${repo}
FOSSIL_VERSION.${repo}?=	--latest

# The cached archive
_FOSSIL_DISTFILE.${repo}=	${PKGBASE}-${repo}.clone

# Define the shell variables used by the following commands
_FOSSIL_CMD.vars.${repo}= \
	repo=${FOSSIL_REPO.${repo}:Q}; \
	extractdir=${FOSSIL_EXTRACTDIR.${repo}:Q}; \
	archive=${_FOSSIL_DISTDIR}/${_FOSSIL_DISTFILE.${repo}:Q}; \
	version=${FOSSIL_VERSION.${repo}:Q}

# Clone remote repository and save it in directory with distfiles
_FOSSIL_CMD.clone_repo.${repo}= \
	if [ ! -f "$$archive" ]; then					\
	  ${STEP_MSG} "Cloning Fossil repository $$repo.";		\
	  ${_FOSSIL_CMD} clone "$$repo" "$$archive";			\
	fi

# Open the cloned repository
_FOSSIL_CMD.open_repo.${repo}= \
	${STEP_MSG} "Opening Fossil repo $${archive\#\#*/}.";		\
	${MKDIR} "$$extractdir";					\
	cd "$$extractdir";						\
	${_FOSSIL_CMD} open --nested "$$archive"

# Pull changes from remote repository and save them in local repository
_FOSSIL_CMD.pull.${repo}= \
	${STEP_MSG} "Pulling changes from $$repo.";			\
	${_FOSSIL_CMD} pull "$$repo"

# Check out the desired version from the local repository
_FOSSIL_CMD.checkout.${repo}= \
	${STEP_MSG} "Checking out $$version.";				\
	${_FOSSIL_CMD} checkout --force "$$version"
.endfor

pre-extract: do-fossil-extract

do-fossil-extract: .PHONY
.for repo in ${FOSSIL_REPOSITORIES}
	${RUN} cd ${WRKDIR};						\
	${MKDIR} ${_FOSSIL_DISTDIR:Q};					\
	${_FOSSIL_CMD.vars.${repo}};					\
	${_FOSSIL_CMD.clone_repo.${repo}};				\
	${_FOSSIL_CMD.open_repo.${repo}};				\
	${_FOSSIL_CMD.pull.${repo}};					\
	${_FOSSIL_CMD.checkout.${repo}};
.endfor

# Debug info for show-all and show-all-fossil
_VARGROUPS+=		fossil
_USER_VARS.fossil+=	CHECKOUT_DATE
_PKG_VARS.fossil+=	FOSSIL_REPO FOSSIL_EXTRACTDIR FOSSIL_VERSION FOSSIL_REPOSITORIES
_SYS_VARS.fossil+=	DISTFILES PKGREVISION WRKSRC
_SYS_VARS.fossil+=	_FOSSIL_DISTDIR
.for repo in ${FOSSIL_REPOSITORIES}
.  for varbase in FOSSIL_REPO FOSSIL_EXTRACTDIR FOSSIL_VERSION
_PKG_VARS.fossil+=	${varbase}.${repo}
.  endfor
.  for varbase in _FOSSIL_DISTFILE
_SYS_VARS.fossil+=	${varbase}.${repo}
.  endfor
.endfor
_USE_VARS.fossil+=	DISTNAME PKGNAME
