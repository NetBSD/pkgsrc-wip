# $NetBSD$
#
# This file provides simple access to Git repositories, so that packages
# can be created from Git instead of from released tarballs. Whenever a
# package is fetched from Git, an archive is created from it and saved
# below ${DISTDIR}, to save bandwidth.
#
# User-settable variables:
#
# CHECKOUT_DATE (optional)
#	Date to check out in ISO format (YYYY-MM-DD).
#
#	When a package doesn't specify a GIT_TAG, it is checked out from
#	the HEAD revision, and the PKGREVISION is set based on the date.
#	To keep this date stable during a bulk build (which may span
#	one or more midnights), this can be set to a fixed date.
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
# GIT_EXTRACTDIR (optional)
#	The directory where the repository is checked out, relative to
#	${WRKDIR}.
#
#	Default:
#		For GIT_EXTRACTDIR, the default value is derived
#		from the last path component of GIT_REPO (so for
#		git://git@github.com:NetBSD/pkgsrc.git, it becomes pkgsrc).
#		For GIT_EXTRACTDIR.${repo}, the default is ${repo}.
#
# GIT_BRANCH (optional)
#	The branch to check out.
#
#	This should seldom be used since it prevents the build from being
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
#	GIT_REPO.first=		git://git@github.com:NetBSD/pkgsrc.git
#	GIT_REVISION.first=	8a311b3069ee79731eec38ca13eb13772cc49223
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

USE_TOOLS+=		git

# Defaults for package-settable variables
DISTFILES?=		# empty
.if defined(CHECKOUT_DATE)
PKGREVISION?=		${CHECKOUT_DATE:S/-//g}
.else
PKGREVISION?=		${_GIT_PKGVERSION:S/.//g}
.endif

# The common case of a single repository
.if defined(GIT_REPO)
GIT_REPOSITORIES+=		default
GIT_EXTRACTDIR.default?=	${GIT_REPO:T:.git=}
WRKSRC?=			${WRKDIR}/${GIT_EXTRACTDIR.default}
.  for varbase in GIT_REPO GIT_BRANCH GIT_REVISION GIT_TAG GIT_ENV
.    if defined(${varbase})
${varbase}.default=		${${varbase}}
.    endif
.  endfor
.endif

GIT_REPOSITORIES?=	# none
.if empty(GIT_REPOSITORIES)
PKG_FAIL_REASON+=	"[git-package.mk] GIT_REPOSITORIES must be set."
.endif

.for repo in ${GIT_REPOSITORIES}
.  if empty(GIT_REPO.${repo})
WARNINGS+=		"[git-package.mk] GIT_REPO."${repo:Q}" must be set."
.  endif
.  if defined(GIT_MODULE.${repo}) # To be removed after 2019-01-01
WARNINGS+=		"[git-package.mk] GIT_MODULE.* is obsolete; use GIT_EXTRACTDIR.${repo} instead."
GIT_EXTRACTDIR.${repo}?= ${GIT_MODULE.${repo}}
.  endif
.endfor

USE_TOOLS+=		date gzip pax

_GIT_CMD=		${TOOLS_PATH.git}
_GIT_CHECKOUT_FLAGS=	--quiet
_GIT_PKGVERSION_CMD=	${DATE} -u +'%Y.%m.%d'
_GIT_PKGVERSION=	${_GIT_PKGVERSION_CMD:sh}
_GIT_DISTDIR=		${DISTDIR}/git-packages

# Definition of repository-specific variables
.for repo in ${GIT_REPOSITORIES}
.  if defined(GIT_MODULE.${repo}) # for backwards compatibility
GIT_EXTRACTDIR.${repo}?=	${GIT_MODULE.${repo}}
.  endif
GIT_EXTRACTDIR.${repo}?=	${repo}
_GIT_ENV.${repo}=		${GIT_ENV.${repo}}

_GIT_CMDLINE.${repo}=	${SETENV} ${_GIT_ENV.${repo}} ${_GIT_CMD}

# determine appropriate checkout branch or tag
.  if defined(GIT_BRANCH.${repo})
_GIT_REV.${repo}=	origin/${GIT_BRANCH.${repo}}
.  elif defined(GIT_REVISION.${repo})
_GIT_REV.${repo}=	${GIT_REVISION.${repo}}
.  elif defined(GIT_TAG.${repo})
_GIT_REV.${repo}=	tags/${GIT_TAG.${repo}}
.  else
_GIT_REV.${repo}=	origin/HEAD
.  endif

_GIT_FETCH_FLAGS.${repo}=	--quiet --recurse-submodules=yes --tags
_GIT_CLONE_FLAGS.${repo}=	--quiet --recursive

# For revision checkout we need deep copy
.  if !defined(GIT_REVISION.${repo}) && !empty(GIT_DEEP_CLONE.${repo}:M[yY][eE][sS])
_GIT_FETCH_FLAGS.${repo}+=	--depth 1
_GIT_CLONE_FLAGS.${repo}+=	--depth 1
.  endif

# The cached archive
_GIT_DISTFILE.${repo}=	${PKGBASE}-${repo}-gitarchive.tar.gz

# Define the shell variables used by the following commands
_GIT_CMD.vars.${repo}= \
	repo=${GIT_REPO.${repo}:Q}; \
	extractdir=${GIT_EXTRACTDIR.${repo}:Q}; \
	archive=${_GIT_DISTDIR}/${_GIT_DISTFILE.${repo}:Q}

# Extract the cached archive
_GIT_CMD.extract_archive.${repo}= \
	if [ -f "$$archive" ]; then					\
	  ${STEP_MSG} "Extracting cached Git archive $${archive\#\#*/}."; \
	  gzip -d -c "$$archive" | pax -r;				\
	fi

# Check out and update the repository
_GIT_CMD.checkout.${repo}= \
	if [ ! -d "$$extractdir" ]; then				\
	  ${STEP_MSG} "Cloning Git repository $$repo.";			\
	  ${_GIT_CMDLINE.${repo}}					\
	    clone ${_GIT_CLONE_FLAGS.${repo}} "$$repo" "$$extractdir";	\
	fi;								\
	\
	${STEP_MSG} "Fetching remote branches.";			\
	${_GIT_CMDLINE.${repo}} -C "$$extractdir"			\
	  remote set-branches origin '*';				\
	\
	${STEP_MSG} "Updating Git working area $$extractdir.";		\
	revision=${_GIT_REV.${repo}:Q};					\
	rev_before=`${_GIT_CMDLINE.${repo}} -C "$$extractdir" rev-parse "$$revision"`; \
	${_GIT_CMDLINE.${repo}} -C "$$extractdir"			\
	  fetch ${_GIT_FETCH_FLAGS.${repo}};				\
	rev_after=`${_GIT_CMDLINE.${repo}} -C "$$extractdir" rev-parse "$$revision"`; \
	\
	checkout_date=${CHECKOUT_DATE:Q};				\
	if [ "$$checkout_date" ]; then					\
	  ${STEP_MSG} "Checking out $$revision at $$checkout_date.";	\
	  ref=`${_GIT_CMDLINE.${repo}} -C "$$extractdir" rev-list -n 1 --before="$${checkout_date}T00:00:01Z" "$$revision"`; \
	  [ "$$ref" ] || ${FAIL_MSG} "[git-package.mk] Cannot find commit for repository "${repo:Q}" revision $$revision at $$checkout_date"; \
	  ${_GIT_CMDLINE.${repo}} -C "$$extractdir"			\
	    checkout ${_GIT_CHECKOUT_FLAGS} "$$ref";			\
	else								\
	  ${STEP_MSG} "Checking out $$revision.";			\
	  ${_GIT_CMDLINE.${repo}} -C "$$extractdir"			\
	    checkout ${_GIT_CHECKOUT_FLAGS} "$$revision";		\
	fi;								\
	\
	${STEP_MSG} "Updating submodules of $$extractdir.";		\
	: "XXX: The revision of the submodules is not correct";		\
	${_GIT_CMDLINE.${repo}} -C "$$extractdir" submodule update --recursive

# TODO: can result in "pax: File name too long for ustar"
# Create the cached archive from the checked out repository
_GIT_CMD.create_archive.${repo}= \
	if [ ! -f "$$archive" -o  "$${rev_before-unknown}" != "$${rev_after-unknown}" ]; then \
	  ${STEP_MSG} "Creating cached Git archive $${archive\#\#*/}.";	\
	  ${MKDIR} "$${archive%/*}";					\
	  pax -w "$$extractdir" | gzip > "$$archive.tmp";		\
	  ${MV} "$$archive.tmp" "$$archive";				\
	fi
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
_USER_VARS.git+=	CHECKOUT_DATE
_PKG_VARS.git=		GIT_REPOSITORIES
_PKG_VARS.git+=		GIT_REPO GIT_EXTRACTDIR GIT_BRANCH GIT_REVISION GIT_TAG GIT_ENV
_SYS_VARS.git=		DISTFILES PKGREVISION WRKSRC
.for repo in ${GIT_REPOSITORIES}
.  for varbase in GIT_REPO GIT_EXTRACTDIR GIT_BRANCH GIT_REVISION GIT_TAG GIT_ENV
_PKG_VARS.git+=		${varbase}.${repo}
.  endfor
.  for varbase in _GIT_REV _GIT_DISTFILE
_SYS_VARS.git+=		${varbase}.${repo}
.  endfor
.endfor
_DEF_VARS.git+=		TOOL_DEPENDS USE_TOOLS WARNINGS _GIT_DISTDIR _GIT_CHECKOUT_FLAGS
_USE_VARS.git+=		PKGBASE DISTDIR WRKDIR TOOLBASE _GIT_PKGVERSION
