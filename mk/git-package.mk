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
#		The git repository
#
# It may define the following variables:
#
#	GIT_TAG
#		The tag to check out (default: HEAD).
#
#	GIT_TAG.${id}
#		Overridable GIT tag for a repository.
#

.if !defined(_PKG_MK_GIT_PACKAGE_MK)
_PKG_MK_GIT_PACKAGE_MK=	# defined

BUILD_DEPENDS+=		scmgit-base>=1.6.4:../../devel/scmgit-base

#
# defaults for user-visible input variables
#

GIT_TAG?=		tip

DISTFILES?=		# empty
.if empty(GIT_TAG) || ${GIT_TAG} == "tip"
PKGREVISION?=		${_GIT_PKGVERSION:S/.//g}
.else
PKGREVISION?=		${GIT_TAG}
.endif

.if !defined(GIT_REPOSITORIES)
PKG_FAIL_REASON+=	"[git-package.mk] GIT_REPOSITORIES must be set."
GIT_REPOSITORIES?=	# none
.endif

.for _repo_ in ${GIT_REPOSITORIES}
.  if !defined(GIT_REPO.${_repo_})
PKG_FAIL_REASON+=	"[git-package.mk] GIT_REPO."${_repo_:Q}" must be set."
.  endif
GIT_TAG.${_repo_}?=	${GIT_TAG}
.endfor

#
# Internal variables
#

_GIT_CMD=		git
_GIT_ENV=		# empty
_GIT_FLAGS=		--quiet --depth 1
_GIT_PKGVERSION_CMD=	${DATE} -u +'%Y.%m.%d'
_GIT_PKGVERSION=	${_GIT_PKGVERSION_CMD:sh}

pre-extract: do-git-extract

.PHONY: do-git-extract
do-git-extract:
.for _repo_ in ${GIT_REPOSITORIES}
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKDIR};							\
	${SETENV} ${_GIT_ENV}						\
		${_GIT_CMD} clone					\
			${_GIT_FLAGS}		 			\
			${GIT_REPO.${_repo_}:Q}
.endfor

.endif
