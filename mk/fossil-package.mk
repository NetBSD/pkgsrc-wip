# $NetBSD$
#
# This file provides simple access to Fossil repositories, so that packages
# can be created from Fossil instead of from released tarballs. Whenever a
# repository is fetched from Fossil, a copy of it is saved below ${DISTDIR},
# to save bandwidth.
#
# Package-settable variables:
#
# FOSSIL_REPO (required)
#	The URL of the Fossil repository.
#
#	If the package needs more than one repository, see
#	FOSSIL_REPOSITORIES below.
#
# FOSSIL_MODULE (optional)
#	The directory where the files are extracted, relative to WRKDIR.
#
#	Default: ${DISTNAME} without the version number
#
# FOSSIL_VERSION (optional)
#	The revision, tag or branch to check out.
#
#	Default: --latest
#
# Packages that access more than one Fossil repository have to list the
# repositories in FOSSIL_REPOSITORIES and configure the remaining variables
# for each repository individually.
#
# FOSSIL_REPOSITORIES (optional)
#	If the package needs multiple Fossil repositories, this
#	is the list of repository IDs. For each of these repositories,
#	parameterized variants of the above variables are defined.
#
#	Example:
#	FOSSIL_REPOSITORIES=	stable latest
#	FOSSIL_REPO.stable=	http://core.tcl.tk/tcl/
#	FOSSIL_MODULE.stable=	stable
#	FOSSIL_VERSION.stable=	v1.2.3
#	FOSSIL_REPO.latest=	http://core.tcl.tk/tcl/
#	FOSSIL_MODULE.latest=	latest
#	FOSSIL_VERSION.latest=	--latest
#
# Keywords: fossil

.if !defined(_PKG_MK_FOSSIL_PACKAGE_MK)
_PKG_MK_FOSSIL_PACKAGE_MK=	# defined

BUILD_DEPENDS+=		fossil-[0-9]*:../../devel/fossil

#
# defaults for user-visible input variables
#

DISTFILES?=		# empty
PKGREVISION?=		${_FOSSIL_PKGREVISION_CMD:sh}

#
# End of the interface part. Start of the implementation part.
#

# The common case of a single repository.
.if defined(FOSSIL_REPO)
FOSSIL_REPOSITORIES+=	_default
FOSSIL_REPO._default=	${FOSSIL_REPO}
FOSSIL_MODULE._default=	${FOSSIL_REPO:S,/$,,:T}
WRKSRC?=		${WRKDIR}/${FOSSIL_MODULE._default}
.endif

#
# Input validation
#

.if !defined(FOSSIL_REPOSITORIES)
PKG_FAIL_REASON+=	"[fossil-package.mk] FOSSIL_REPOSITORIES must be set."
FOSSIL_REPOSITORIES?=	# none
.endif

.for repo in ${FOSSIL_REPOSITORIES}
.  if !defined(FOSSIL_REPO.${repo})
PKG_FAIL_REASON+=	"[fossil-package.mk] FOSSIL_REPO."${repo:Q}" must be set."
.  endif
.endfor

#
# Internal variables
#

USE_TOOLS+=			date pax

_FOSSIL_CMD=			fossil
_FOSSIL_PKGREVISION_CMD=	${DATE} -u +'%Y%m%d'
_FOSSIL_DISTDIR=		${DISTDIR}/fossil-packages

#
# Generation of repository-specific variables
#

.for repo in ${FOSSIL_REPOSITORIES}
FOSSIL_MODULE.${repo}?=		${repo}
FOSSIL_VERSION.${repo}?=	--latest

# The cached archive
_FOSSIL_DISTFILE.${repo}=	${PKGBASE}-${FOSSIL_MODULE.${repo}}.clone

# Define the shell variables used by the following commands
_FOSSIL_CMD.vars.${repo}= \
	repo=${FOSSIL_REPO.${repo}:Q}; \
	module=${FOSSIL_MODULE.${repo}:Q}; \
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
	${MKDIR} "$$module";						\
	cd "$$module";							\
	${_FOSSIL_CMD} open "$$archive";				\
	cd ${WRKDIR}

# Pull changes from remote repository and save them in local repository
_FOSSIL_CMD.pull.${repo}= \
	${STEP_MSG} "Pulling changes from $$repo.";			\
	cd "$$module";							\
	${_FOSSIL_CMD} pull "$$repo";					\
	cd ${WRKDIR}

# Check out the desired version from the local repository
_FOSSIL_CMD.checkout.${repo}= \
	${STEP_MSG} "Checking out $$version.";				\
	cd "$$module";							\
	${_FOSSIL_CMD} checkout --force "$$version";			\
	cd ${WRKDIR}
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
_PKG_VARS.fossil+=	FOSSIL_REPO FOSSIL_MODULE FOSSIL_VERSION FOSSIL_REPOSITORIES
_SYS_VARS.fossil+=	DISTFILES PKGREVISION WRKSRC
_SYS_VARS.fossil+=	_FOSSIL_DISTDIR
.for repo in ${FOSSIL_REPOSITORIES}
.  for varbase in FOSSIL_REPO FOSSIL_MODULE FOSSIL_VERSION
_PKG_VARS.fossil+=	${varbase}.${repo}
.  endfor
.  for varbase in _FOSSIL_DISTFILE
_SYS_VARS.fossil+=	${varbase}.${repo}
.  endfor
.endfor

.endif
