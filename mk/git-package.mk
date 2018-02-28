# $NetBSD$
#
# This file provides simple access to Git repositories, so that packages
# can be created from Git instead of from released tarballs. Whenever a
# package is fetched from Git, an archive is created from it and saved
# below ${DISTDIR}, to save bandwidth.
#
# Package-settable variables:
#
# GIT_REPO (required)
#	The URL of the Git repository.
#
#	If the package needs more than one repository, see GIT_REPOSITORIES
#	below.
#
#	Examples:
#		https://github.com/NetBSD/pkgsrc
#		git://git@github.com:NetBSD/pkgsrc.git
#		git@github.com:NetBSD/pkgsrc.git
#
# GIT_MODULE (optional)
#	The name of the Git module.
#
#	This is where the repository gets extracted.
#
#	Default:
#		For the GIT_MODULE variable, the default value is derived
#		from the last path component of GIT_REPO (so for
#		git://git@github.com:NetBSD/pkgsrc.git, it becomes pkgsrc).
#		For the GIT_MODULE.${repo} variables, the default is ${repo}.
#
# GIT_BRANCH (optional)
#	The branch to check out.
#
#	This should seldomly be used since it prevents the build from being
#	reproducible. Prefer a tag or a revision instead.
#
# GIT_REVISION (optional)
#	The revision to check out.
#
#	Example: 8a311b3069ee79731eec38ca13eb13772cc49223
#
# GIT_TAG (optional)
#	The tag to check out.
#
#	Example: v1.0.0
#
# GIT_ENV (optional)
#	The environment variables for the git commands.
#
#	Example: GIT_SSL_NO_VERIFY=true
#
# GIT_REPOSITORIES (optional)
#	For packages that need multiple Git repositories, this is the list
#	of repository IDs. Each of these repositories is configured separately,
#	using parameterized variables like GIT_REPO.${repo} instead of the
#	above GIT_REPO.
#
#	Example:
#	GIT_REPOSITORIES=	first second
#	GIT_MODULE.first=	first
#	GIT_REPO.first=		git://git@github.com:NetBSD/pkgsrc.git
#	GIT_REVISION.first=	8a311b3069ee79731eec38ca13eb13772cc49223
#	GIT_MODULE.second=	second
#	GIT_REPO.second=	git://git@github.com:NetBSD/pkgsrc.git
#	GIT_BRANCH.second=	master
#
# Variables set by this file:
#
# DISTFILES
#	Defaults to an empty list.
#	This means that MASTER_SITES does not need to be defined.
#
# PKGREVISION
#	Defaults to today in the format yyyymmdd, e.g. 20180225.
#	This keeps the packages distinguishable since the HEAD might
#	change anytime.
#
# Keywords: git github

.if !defined(_PKG_MK_GIT_PACKAGE_MK)
_PKG_MK_GIT_PACKAGE_MK=	# defined

BUILD_DEPENDS+=		git-base>=1.6.4:../../devel/git-base

#
# defaults for user-visible input variables
#

DISTFILES?=		# empty
PKGREVISION?=		${_GIT_PKGVERSION:S/.//g}

#
# End of the interface part. Start of the implementation part.
#

# The common case of a single repository
.if defined(GIT_REPO)
GIT_MODULE._default?=	${GIT_REPO:T:.git=}
GIT_REPOSITORIES+=	_default
WRKSRC?=		${WRKDIR}/${GIT_MODULE._default}
.  for varbase in GIT_REPO GIT_BRANCH GIT_REVISION GIT_TAG GIT_ENV
.    if defined(${varbase})
${varbase}._default=	${${varbase}}
.    endif
.  endfor
.endif

#
# Input validation
#

.if !defined(GIT_REPOSITORIES)
PKG_FAIL_REASON+=	"[git-package.mk] GIT_REPOSITORIES must be set."
GIT_REPOSITORIES?=	# none
.endif

.for repo in ${GIT_REPOSITORIES}
.  if !defined(GIT_REPO.${repo})
PKG_FAIL_REASON+=	"[git-package.mk] GIT_REPO."${repo:Q}" must be set."
.  endif
.endfor

#
# Internal variables
#

USE_TOOLS+=		date pax

_GIT_CMD=		git
_GIT_CHECKOUT_FLAGS=	--quiet
_GIT_PKGVERSION_CMD=	${DATE} -u +'%Y.%m.%d'
_GIT_PKGVERSION=	${_GIT_PKGVERSION_CMD:sh}
_GIT_DISTDIR=		${DISTDIR}/git-packages

#
# Generation of repository-specific variables
#

.for repo in ${GIT_REPOSITORIES}
GIT_MODULE.${repo}?=	${repo}
_GIT_ENV.${repo}=	${GIT_ENV.${repo}}

_GIT_CMDLINE.${repo}=	${SETENV} ${_GIT_ENV.${repo}} ${_GIT_CMD}

# determine appropriate checkout branch or tag
.  if defined(GIT_BRANCH.${repo})
_GIT_FLAG.${repo}=	origin/${GIT_BRANCH.${repo}}
.  elif defined(GIT_REVISION.${repo})
_GIT_FLAG.${repo}=	${GIT_REVISION.${repo}}
.  elif defined(GIT_TAG.${repo})
_GIT_FLAG.${repo}=	tags/${GIT_TAG.${repo}}
.  else
_GIT_FLAG.${repo}=	origin/HEAD
.  endif

_GIT_FETCH_FLAGS.${repo}=	--quiet --recurse-submodules=yes --tags
_GIT_CLONE_FLAGS.${repo}=	--quiet --recursive

# For revision checkout we need deep copy
. if !defined(GIT_REVISION.${repo}) && !empty(GIT_DEEP_CLONE.${repo}:M[yY][eE][sS])
_GIT_FETCH_FLAGS.${repo}+=	--depth 1
_GIT_CLONE_FLAGS.${repo}+=	--depth 1
. endif

# The cached archive
_GIT_DISTFILE.${repo}=	${PKGBASE}-${GIT_MODULE.${repo}}-gitarchive.tar.gz

# Define the shell variables used by the following commands
_GIT_CMD.vars.${repo}= \
	repo=${GIT_REPO.${repo}:Q}; \
	module=${GIT_MODULE.${repo}:Q}; \
	archive=${_GIT_DISTDIR}/${_GIT_DISTFILE.${repo}:Q}

# Extract the cached archive
_GIT_CMD.extract_archive.${repo}= \
	if [ -f "$$archive" ]; then					\
	  ${STEP_MSG} "Extracting cached Git archive $${archive\#\#*/}."; \
	  gzip -d -c "$$archive" | pax -r;				\
	fi

# Check out and update the repository
_GIT_CMD.checkout.${repo}= \
	if [ ! -d "$$module" ]; then					\
	  ${STEP_MSG} "Cloning Git archive $$module.";			\
	  ${_GIT_CMDLINE.${repo}}					\
	    clone ${_GIT_CLONE_FLAGS.${repo}} "$$repo" "$$module";	\
	fi;								\
	\
	${STEP_MSG} "Fetching remote branches of "${_GIT_FLAG.${repo}:Q}"."; \
	${_GIT_CMDLINE.${repo}} -C "$$module"				\
	  remote set-branches origin '*';				\
	\
	${STEP_MSG} "Updating Git archive $$module.";			\
	${_GIT_CMDLINE.${repo}} -C "$$module"				\
	  fetch ${_GIT_FETCH_FLAGS.${repo}};				\
	\
	${STEP_MSG} "Checking out Git "${_GIT_FLAG.${repo}:Q}".";	\
	${_GIT_CMDLINE.${repo}} -C "$$module"				\
	  checkout ${_GIT_CHECKOUT_FLAGS} ${_GIT_FLAG.${repo}:Q};	\
	\
	${STEP_MSG} "Updating submodules of $$module.";			\
	${_GIT_CMDLINE.${repo}} -C "$$module" submodule update --recursive

# Create the cached archive from the checked out repository
_GIT_CMD.create_archive.${repo}= \
	${STEP_MSG} "Creating cached Git archive $${archive\#\#*/}.";	\
	${MKDIR} "$${archive%/*}";					\
	pax -w "$$module" | gzip > "$$archive.tmp";			\
	${MV} "$$archive.tmp" "$$archive"
.endfor

pre-extract: do-git-extract

do-git-extract: .PHONY
.for repo in ${GIT_REPOSITORIES}
	${RUN} \
	cd ${WRKDIR}; \
	${_GIT_CMD.vars.${repo}}; \
	${_GIT_CMD.extract_archive.${repo}}; \
	${_GIT_CMD.checkout.${repo}}; \
	${_GIT_CMD.create_archive.${repo}}
.endfor

# Debug info for show-all and show-all-git
_VARGROUPS+=		git
_PKG_VARS.git=		GIT_REPOSITORIES
_PKG_VARS.git+=		GIT_REPO GIT_MODULE GIT_BRANCH GIT_REVISION GIT_TAG GIT_ENV
_SYS_VARS.git=		DISTFILES PKGREVISION WRKSRC
.for repo in ${GIT_REPOSITORIES}
.  for varbase in GIT_REPO GIT_MODULE GIT_BRANCH GIT_REVISION GIT_TAG GIT_ENV
_PKG_VARS.git+=		${varbase}.${repo}
.  endfor
.  for varbase in _GIT_FLAG _GIT_DISTFILE
_SYS_VARS.git+=		${varbase}.${repo}
.  endfor
.endfor

.endif
