# $NetBSD$
#
# This file provides simple access to Git repositories, so that packages
# can be created from Git instead of from released tarballs.
#
# Package-settable variables:
#
# GIT_REPO
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
#
#		GIT_REPOSITORIES=	first second
#		GIT_MODULE.first=	first
#		GIT_REPO.first=		git://git@github.com:NetBSD/pkgsrc.git
#		GIT_REVISION.first=	8a311b3069ee79731eec38ca13eb13772cc49223
#		GIT_MODULE.second=	second
#		GIT_REPO.second=	git://git@github.com:NetBSD/pkgsrc.git
#		GIT_BRANCH.second=	master
#
# Variables set by this file:
#
# DISTFILES
#	Defaults to an empty list, which means that MASTER_SITES does not
#	need to be defined.
#
# PKGREVISION
#	Defaults to the current date in the format yyyymmdd, e.g. 20180225.
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

# The standard case of a single repository
.if defined(GIT_REPO)
GIT_REPOSITORIES+=	_default
.  for varbase in GIT_REPO GIT_BRANCH GIT_REVISION GIT_TAG GIT_ENV
.    if defined(${varbase})
${varbase}._default=	${${varbase}}
.    endif
.  endfor
GIT_MODULE._default?=	${GIT_REPO:T:.git=}
WRKSRC?=		${WRKDIR}/${GIT_MODULE._default}
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

# Debug info for show-all and show-all-git
_VARGROUPS+=		git
_PKG_VARS.git=		GIT_REPOSITORIES
_PKG_VARS.git+=		GIT_REPO GIT_MODULE GIT_BRANCH GIT_REVISION GIT_TAG GIT_ENV
.for repo in ${GIT_REPOSITORIES}
.  for pkgvar in GIT_REPO GIT_MODULE GIT_BRANCH GIT_REVISION GIT_TAG GIT_ENV
_PKG_VARS.git+=		${pkgvar}.${repo}
.  endfor
.  for sysvar in _GIT_FLAG _GIT_DISTFILE
_SYS_VARS.git+=		${sysvar}.${repo}
.  endfor
.endfor
_SYS_VARS.git=		DISTFILES PKGREVISION WRKSRC

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


.for repo in ${GIT_REPOSITORIES}
GIT_MODULE.${repo}?=	${repo}
_GIT_ENV.${repo}=	${GIT_ENV.${repo}}

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

# Cache support:
#   cache file name
_GIT_DISTFILE.${repo}=	${PKGBASE}-${GIT_MODULE.${repo}}-gitarchive.tar.gz

#   command to extract cache file
_GIT_EXTRACT_CACHED.${repo}=	\
	if [ -f ${_GIT_DISTDIR}/${_GIT_DISTFILE.${repo}:Q} ]; then		\
	  ${STEP_MSG} "Extracting cached Git archive "${_GIT_DISTFILE.${repo}:Q}"."; \
	  gzip -d -c ${_GIT_DISTDIR}/${_GIT_DISTFILE.${repo}:Q} | pax -r;	\
	fi

#   create cache archive
_GIT_CREATE_CACHE.${repo}=	\
	${STEP_MSG} "Creating cached Git archive "${_GIT_DISTFILE.${repo}:Q}"."; \
	${MKDIR} ${_GIT_DISTDIR:Q};					\
	pax -w ${GIT_MODULE.${repo}:Q} | gzip > ${_GIT_DISTDIR}/${_GIT_DISTFILE.${repo}:Q}.tmp;	\
	${MV} '${_GIT_DISTDIR}/${_GIT_DISTFILE.${repo}:Q}.tmp' '${_GIT_DISTDIR}/${_GIT_DISTFILE.${repo}:Q}'

#   fetch Git repo or update cached one
_GIT_FETCH_REPO.${repo}=	\
	if [ ! -d ${GIT_MODULE.${repo}:Q} ]; then				\
	  ${STEP_MSG} "Cloning Git archive "${GIT_MODULE.${repo}:Q}".";		\
	  ${SETENV} ${_GIT_ENV.${repo}} ${_GIT_CMD}				\
	    clone ${_GIT_CLONE_FLAGS.${repo}}					\
	    ${GIT_REPO.${repo}:Q} ${GIT_MODULE.${repo}:Q};			\
	fi;									\
	${STEP_MSG} "Fetching remote branches of "${_GIT_FLAG.${repo}:Q}".";	\
	${SETENV} ${_GIT_ENV.${repo}} ${_GIT_CMD} -C ${GIT_MODULE.${repo}:Q}	\
	  remote set-branches origin '*';					\
	${STEP_MSG} "Updating Git archive "${GIT_MODULE.${repo}:Q}".";		\
	${SETENV} ${_GIT_ENV.${repo}} ${_GIT_CMD} -C ${GIT_MODULE.${repo}:Q}	\
	  fetch ${_GIT_FETCH_FLAGS.${repo}};					\
	${STEP_MSG} "Checking out Git "${_GIT_FLAG.${repo}:Q}".";		\
	${SETENV} ${_GIT_ENV.${repo}} ${_GIT_CMD} -C ${GIT_MODULE.${repo}:Q}	\
	  checkout ${_GIT_CHECKOUT_FLAGS} ${_GIT_FLAG.${repo}:Q};		\
	${STEP_MSG} "Updating submodules of "${_GIT_FLAG.${repo}:Q}".";		\
	${SETENV} ${_GIT_ENV.${repo}} ${_GIT_CMD} -C ${GIT_MODULE.${repo}:Q}	\
	  submodule update --recursive
.endfor

pre-extract: do-git-extract

.PHONY: do-git-extract
do-git-extract:
.for repo in ${GIT_REPOSITORIES}
	${RUN} cd ${WRKDIR};							\
	if [ ! -d ${_GIT_DISTDIR:Q} ]; then mkdir -p ${_GIT_DISTDIR:Q}; fi;	\
	${_GIT_EXTRACT_CACHED.${repo}};						\
	${_GIT_FETCH_REPO.${repo}};						\
	${_GIT_CREATE_CACHE.${repo}};

.endfor

.endif
