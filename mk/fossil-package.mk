# This file provides simple access to Fossil repositories, so that packages
# can be created from Fossil instead of from released tarballs.
#
# A package using this file shall define the following variables:
#
#	FOSSIL_REPOSITORIES
#		A list of unique identifiers /id/ for which appropriate
#		FOSSIL_REPO must be defined.
#
#	FOSSIL_REPO.${id}
#		The fossil repository
#
# It may define the following variables:
#
#	FOSSIL_BRANCH.${id}
#		The branch to check out.
#
#	FOSSIL_REVISION.${id}
#		The revision to check out.
#
#	FOSSIL_TAG.${id}
#		Overridable FOSSIL tag for a repository.
#
#	FOSSIL_ENV.${id}
#		The environment for fossil, to set e.g. FOSSIL_SSL_NO_VERIFY=true

.if !defined(_PKG_MK_FOSSIL_PACKAGE_MK)
_PKG_MK_FOSSIL_PACKAGE_MK=	# defined

BUILD_DEPENDS+=		fossil-[0-9]*:../../devel/fossil

#
# defaults for user-visible input variables
#

DISTFILES?=		# empty
PKGREVISION?=		${_FOSSIL_PKGVERSION:S/.//g}

#
# End of the interface part. Start of the implementation part.
#

#
# Input validation
#

.if !defined(FOSSIL_REPOSITORIES)
PKG_FAIL_REASON+=	"[fossil-package.mk] FOSSIL_REPOSITORIES must be set."
FOSSIL_REPOSITORIES?=	# none
.endif

.for _repo_ in ${FOSSIL_REPOSITORIES}
.  if !defined(FOSSIL_REPO.${_repo_})
PKG_FAIL_REASON+=	"[fossil-package.mk] FOSSIL_REPO."${_repo_:Q}" must be set."
.  endif
.endfor

#
# Internal variables
#

USE_TOOLS+=		date pax

_FOSSIL_CMD=		fossil
_FOSSIL_PKGVERSION_CMD=	${DATE} -u +'%Y.%m.%d'
_FOSSIL_PKGVERSION=	${_FOSSIL_PKGVERSION_CMD:sh}
_FOSSIL_DISTDIR=	${DISTDIR}/fossil-packages

#
# Generation of repository-specific variables
#

.for repo in ${FOSSIL_REPOSITORIES}
FOSSIL_MODULE.${repo}?=	${repo}
_FOSSIL_ENV.${repo}=	${FOSSIL_ENV.${repo}}

# In reality there is no difference for fossil
.  if defined(FOSSIL_BRANCH.${repo})
_FOSSIL_VERSION.${repo}=	${FOSSIL_BRANCH.${repo}}
.  elif defined(FOSSIL_REVISION.${repo})
_FOSSIL_VERSION.${repo}=	${FOSSIL_REVISION.${repo}}
.  elif defined(FOSSIL_TAG.${repo})
_FOSSIL_VERSION.${repo}=	${FOSSIL_TAG.${repo}}
.  else
_FOSSIL_VERSION.${repo}=	--latest
.  endif

# Ignore modified files in the current checkout
_FOSSIL_FLAG.${repo}=	--force ${_FOSSIL_VERSION.${repo}}

# Cache support:
#   cache file name
_FOSSIL_DISTFILE.${repo}=	${PKGBASE}-${FOSSIL_MODULE.${repo}}.clone
_FOSSIL_CLONE.${repo}=		${_FOSSIL_DISTDIR:Q}/${_FOSSIL_DISTFILE.${repo}:Q}

#   clone remote repository and save it in directory with distfiles
_FOSSIL_CLONE_REPO.${repo}=	\
	if [ ! -f ${_FOSSIL_DISTDIR}/${_FOSSIL_DISTFILE.${repo}:Q} ]; then	\
	  ${STEP_MSG} "Cloning FOSSIL archive "${_FOSSIL_DISTFILE.${repo}:Q}".";\
	  ${SETENV} ${_FOSSIL_ENV.${repo}} ${_FOSSIL_CMD}			\
	    clone ${_FOSSIL_CLONE_FLAGS.${repo}}				\
	    ${FOSSIL_REPO.${repo}:Q} ${_FOSSIL_CLONE.${repo}};			\
	fi

#   open cloned repository
_FOSSIL_OPEN_REPO.${repo}=	\
	${MKDIR} -p ${FOSSIL_MODULE.${repo}:Q};					\
	(									\
		${STEP_MSG} "Opening FOSSIL repo "${_FOSSIL_DISTFILE.${repo}:Q}".";\
		cd ${FOSSIL_MODULE.${repo}:Q}; 					\
		${SETENV} ${_FOSSIL_ENV.${repo}} ${_FOSSIL_CMD}			\
		  open ${_FOSSIL_CLONE.${repo}};				\
	)

#   pull changs from remote repository, save in local clone and checkout it
_FOSSIL_PULL_VERSION.${repo}=	\
	if [ ! -d ${FOSSIL_MODULE.${repo}:Q} ]; then				\
	  ${STEP_MSG} "Cannot pull changes. Missing "${FOSSIL_MODULE.${repo}:Q}".";	\
	fi;									\
	(									\
		cd ${FOSSIL_MODULE.${repo}:Q};					\
		${STEP_MSG} "Pulling changes from "${_FOSSIL_FLAG.${repo}:Q}".";\
		${SETENV} ${_FOSSIL_ENV.${repo}} ${_FOSSIL_CMD}			\
		  pull ${FOSSIL_REPO.${repo}:Q};				\
		${STEP_MSG} "Checkout "${_FOSSIL_VERSION.${repo}:Q}".";		\
		${SETENV} ${_FOSSIL_ENV.${repo}} ${_FOSSIL_CMD}			\
		  checkout ${_FOSSIL_FLAG.${repo}}				\
	)

.endfor

pre-extract: do-fossil-extract

.PHONY: do-fossil-extract
do-fossil-extract:
.for _repo_ in ${FOSSIL_REPOSITORIES}
	${RUN} cd ${WRKDIR};							\
	if [ ! -d ${_FOSSIL_DISTDIR:Q} ]; then 					\
		mkdir -p ${_FOSSIL_DISTDIR:Q};					\
	fi;									\
	${_FOSSIL_CLONE_REPO.${_repo_}};					\
	${_FOSSIL_OPEN_REPO.${_repo_}};						\
	${_FOSSIL_PULL_VERSION.${_repo_}};

.endfor

.endif
