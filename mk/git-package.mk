# $NetBSD$
#
# This file provides simple access to git repositories, so that packages
# can be created from git instead of from released tarballs.
#
# A package using this file shall define the following variables:
#
#	GIT_REPOSITORIES
#		A list of unique identifiers /id/ for which appropriate
#		GIT_REPO must be defined.
#
#	GIT_REPO.${id}
#		The git repository.
#
#		Examples:
#			https://github.com/NetBSD/pkgsrc
#			git://git@github.com:NetBSD/pkgsrc.git
#			git@github.com:NetBSD/pkgsrc.git
#
# It may define the following variables:
#
#	GIT_BRANCH.${id}
#		The branch to check out.
#
#		This should seldomly be used since it prevents the build
#		from being reproducible. Prefer a tag or a revision
#		instead.
#
#	GIT_REVISION.${id}
#		The revision to check out.
#
#		Example: 4b825dc642cb6eb9a060e54bf8d69288fbee4904
#
#	GIT_TAG.${id}
#		The tag to check out.
#
#		Example: v1.0.0
#
#	GIT_ENV.${id}
#		The environment variables for the git command.
#
#		Example: GIT_SSL_NO_VERIFY=true
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
	  ${STEP_MSG} "Extracting cached GIT archive "${_GIT_DISTFILE.${repo}:Q}"."; \
	  gzip -d -c ${_GIT_DISTDIR}/${_GIT_DISTFILE.${repo}:Q} | pax -r;	\
	fi

#   create cache archive
_GIT_CREATE_CACHE.${repo}=	\
	${STEP_MSG} "Creating cached GIT archive "${_GIT_DISTFILE.${repo}:Q}"."; \
	${MKDIR} ${_GIT_DISTDIR:Q};					\
	pax -w ${GIT_MODULE.${repo}:Q} | gzip > ${_GIT_DISTDIR}/${_GIT_DISTFILE.${repo}:Q}.tmp;	\
	${MV} '${_GIT_DISTDIR}/${_GIT_DISTFILE.${repo}:Q}.tmp' '${_GIT_DISTDIR}/${_GIT_DISTFILE.${repo}:Q}'

#   fetch git repo or update cached one
_GIT_FETCH_REPO.${repo}=	\
	if [ ! -d ${GIT_MODULE.${repo}:Q} ]; then				\
	  ${STEP_MSG} "Cloning GIT archive "${GIT_MODULE.${repo}:Q}".";		\
	  ${SETENV} ${_GIT_ENV.${repo}} ${_GIT_CMD}				\
	    clone ${_GIT_CLONE_FLAGS.${repo}}					\
	    ${GIT_REPO.${repo}:Q} ${GIT_MODULE.${repo}:Q};			\
	fi;									\
	${STEP_MSG} "Fetching remote branches of "${_GIT_FLAG.${repo}:Q}".";	\
	${SETENV} ${_GIT_ENV.${repo}} ${_GIT_CMD} -C ${GIT_MODULE.${repo}:Q}	\
	  remote set-branches origin '*';					\
	${STEP_MSG} "Updating GIT archive "${GIT_MODULE.${repo}:Q}".";		\
	${SETENV} ${_GIT_ENV.${repo}} ${_GIT_CMD} -C ${GIT_MODULE.${repo}:Q}	\
	  fetch ${_GIT_FETCH_FLAGS.${repo}};					\
	${STEP_MSG} "Checking out GIT "${_GIT_FLAG.${repo}:Q}".";		\
	${SETENV} ${_GIT_ENV.${repo}} ${_GIT_CMD} -C ${GIT_MODULE.${repo}:Q}	\
	  checkout ${_GIT_CHECKOUT_FLAGS} ${_GIT_FLAG.${repo}:Q};		\
	${STEP_MSG} "Updating submodules of "${_GIT_FLAG.${repo}:Q}".";		\
	${SETENV} ${_GIT_ENV.${repo}} ${_GIT_CMD} -C ${GIT_MODULE.${repo}:Q}	\
	  submodule update --recursive
.endfor

pre-extract: do-git-extract

.PHONY: do-git-extract
do-git-extract:
.for _repo_ in ${GIT_REPOSITORIES}
	${RUN} cd ${WRKDIR};							\
	if [ ! -d ${_GIT_DISTDIR:Q} ]; then mkdir -p ${_GIT_DISTDIR:Q}; fi;	\
	${_GIT_EXTRACT_CACHED.${_repo_}};					\
	${_GIT_FETCH_REPO.${_repo_}};						\
	${_GIT_CREATE_CACHE.${_repo_}};

.endfor

.endif
