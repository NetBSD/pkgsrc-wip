# This file provides simple access to git repositories, so that packages
# can be created from git instead of from released tarballs.
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

# Cache support:
#   cache file name
_FOSSIL_DISTFILE.${repo}=	${PKGBASE}-${FOSSIL_MODULE.${repo}}-fossilarchive.tar.gz

#   command to extract cache file
_FOSSIL_EXTRACT_CACHED.${repo}=	\
	if [ -f ${_FOSSIL_DISTDIR}/${_FOSSIL_DISTFILE.${repo}:Q} ]; then		\
	  ${STEP_MSG} "Extracting cached FOSSIL archive "${_FOSSIL_DISTFILE.${repo}:Q}"."; \
	  gzip -d -c ${_FOSSIL_DISTDIR}/${_FOSSIL_DISTFILE.${repo}:Q} | pax -r;	\
	fi

#   create cache archive
_FOSSIL_CREATE_CACHE.${repo}=	\
	${STEP_MSG} "Creating cached FOSSIL archive "${_FOSSIL_DISTFILE.${repo}:Q}"."; \
	${MKDIR} ${_FOSSIL_DISTDIR:Q};					\
	pax -w ${FOSSIL_MODULE.${repo}:Q} | gzip > ${_FOSSIL_DISTDIR}/${_FOSSIL_DISTFILE.${repo}:Q}.tmp;	\
	${MV} '${_FOSSIL_DISTDIR}/${_FOSSIL_DISTFILE.${repo}:Q}.tmp' '${_FOSSIL_DISTDIR}/${_FOSSIL_DISTFILE.${repo}:Q}'

#   fetch fossil repo or update cached one
_FOSSIL_FETCH_REPO.${repo}=	\
	if [ ! -d ${FOSSIL_MODULE.${repo}:Q} ]; then				\
	  ${STEP_MSG} "Cloning FOSSIL archive "${FOSSIL_MODULE.${repo}:Q}".";	\
	  ${SETENV} ${_FOSSIL_ENV.${repo}} ${_FOSSIL_CMD}			\
	    clone ${_FOSSIL_CLONE_FLAGS.${repo}}				\
	    ${FOSSIL_REPO.${repo}:Q} ${FOSSIL_MODULE.${repo}:Q};		\
	fi;									\
	${STEP_MSG} "Fetching remote repo of "${_FOSSIL_FLAG.${repo}:Q}".";	\
	( cd ${FOSSIL_MODULE.${repo}:Q} && ${_FOSSIL_CMD} pull )
.endfor

pre-extract: do-fossil-extract

.PHONY: do-fossil-extract
do-fossil-extract:
.for _repo_ in ${FOSSIL_REPOSITORIES}
	${RUN} cd ${WRKDIR};							\
	if [ ! -d ${_FOSSIL_DISTDIR:Q} ]; then 					\
		mkdir -p ${_FOSSIL_DISTDIR:Q};					\
	fi;									\
	${_FOSSIL_EXTRACT_CACHED.${_repo_}};					\
	${_FOSSIL_FETCH_REPO.${_repo_}};					\
	${_FOSSIL_CREATE_CACHE.${_repo_}};

.endfor

.endif
