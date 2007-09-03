# This file provides simple access to Mercurial repositories, so that packages
# can be created from Mercurial instead of from released tarballs.
#
# A package using this file shall define the following variables:
#
#	HG_REPOSITORIES
#		A list of unique identifiers /id/ for which appropriate
#		HG_REPO must be defined.
#
#	HG_REPO.${id}
#		The Mercurial repository
#
# It may define the following variables:
#
#	HG_TAG
#		The HG tag to check out (default: HEAD).
#
#	HG_TAG.${id}
#		Overridable HG tag for a repository.
#

.if !defined(_PKG_MK_HG_PACKAGE_MK)
_PKG_MK_HG_PACKAGE_MK=	# defined

BUILD_DEPENDS+=		mercurial>=0.9:../../devel/mercurial

#
# defaults for user-visible input variables
#

HG_TAG?=		tip
DISTFILES?=		# empty

.if !defined(HG_REPOSITORIES)
PKG_FAIL_REASON+=	"[hg-package.mk] HG_REPOSITORIES must be set."
HG_REPOSITORIES?=	# none
.endif

.for _repo_ in ${HG_REPOSITORIES}
.  if !defined(HG_REPO.${_repo_})
PKG_FAIL_REASON+=	"[hg-package.mk] HG_REPO."${_repo_:Q}" must be set."
.  endif
HG_TAG.${_repo_}?=	${HG_TAG}
.endfor

#
# Internal variables
#

_HG_CONFIG_DIR=	${WRKDIR}/.hg
_HG_CMD=		hg
_HG_ENV=		# empty
_HG_FLAGS=		-q

pre-extract: do-hg-extract

.PHONY: do-hg-extract
do-hg-extract:
.for _repo_ in ${HG_REPOSITORIES}
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKDIR};							\
	${SETENV} ${_HG_ENV}						\
		${_HG_CMD} clone					\
			-r ${HG_TAG.${_repo_}:Q}			\
			${_HG_FLAGS}		 			\
			${HG_REPO.${_repo_}:Q}
.endfor

.endif
