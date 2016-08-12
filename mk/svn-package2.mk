# This file provides simple access to svn repositories, so that packages
# can be created from svn instead of from released tarballs.
#
# A package using this file shall define the following variables:
#
#	SVN_REPOSITORIES
#		A list of unique identifiers /id/ for which appropriate
#		SVN_REPO must be defined.
#
#	SVN_REPO.${id}
#		The svn repository
#
# It may define the following variables:
#
#	SVN_BRANCH.${id}
#		The branch to check out.
#
#	SVN_REVISION.${id}
#		The revision to check out.
#
#	SVN_TAG.${id}
#		Overridable SVN tag for a repository.
#
#	SVN_ENV.${id}
#		The environment for svn

.if !defined(_PKG_MK_SVN_PACKAGE_MK)
_PKG_MK_SVN_PACKAGE_MK=	# defined

BUILD_DEPENDS+=		subversion-base-[0-9]*:../../devel/subversion-base

#
# defaults for user-visible input variables
#

DISTFILES?=		# empty
PKGREVISION?=		${_SVN_PKGVERSION:S/.//g}

#
# End of the interface part. Start of the implementation part.
#

#
# Input validation
#

.if !defined(SVN_REPOSITORIES)
PKG_FAIL_REASON+=	"[svn-package2.mk] SVN_REPOSITORIES must be set."
SVN_REPOSITORIES?=	# none
.endif

.for _repo_ in ${SVN_REPOSITORIES}
.  if !defined(SVN_REPO.${_repo_})
PKG_FAIL_REASON+=	"[svn-package2.mk] SVN_REPO."${_repo_:Q}" must be set."
.  endif
.endfor

#
# Internal variables
#

USE_TOOLS+=		date pax

_SVN_CMD=		svn
_SVN_CONFIG_DIR=	${WRKDIR}/.subversion
_SVN_CHECKOUT_FLAGS=	--config-dir=${_SVN_CONFIG_DIR} --non-interactive
_SVN_PKGVERSION_CMD=	${DATE} -u +'%Y.%m.%d'
_SVN_PKGVERSION=	${_SVN_PKGVERSION_CMD:sh}
_SVN_DISTDIR=		${DISTDIR}/svn-packages

#
# Generation of repository-specific variables


.for repo in ${SVN_REPOSITORIES}
SVN_MODULE.${repo}?=	${repo}
_SVN_ENV.${repo}=	${SVN_ENV.${repo}}

# determine appropriate checkout option
.  if defined(SVN_REVISION.${repo})
_SVN_FLAG.${repo}=	-r ${SVN_REVISION.${repo}}
.  else
_SVN_FLAG.${repo}=	-r HEAD
.  endif

# Cache support:
#   cache file name
_SVN_DISTFILE.${repo}=	${PKGBASE}-${SVN_MODULE.${repo}}-svnarchive.tar.gz

#   command to extract cache file
_SVN_EXTRACT_CACHED.${repo}=	\
	if [ -f ${_SVN_DISTDIR}/${_SVN_DISTFILE.${repo}:Q} ]; then		\
	  ${STEP_MSG} "Extracting cached SVN archive "${_SVN_DISTFILE.${repo}:Q}"."; \
	  gzip -d -c ${_SVN_DISTDIR}/${_SVN_DISTFILE.${repo}:Q} | pax -r;	\
	fi

#   create cache archive
_SVN_CREATE_CACHE.${repo}=	\
	${STEP_MSG} "Creating cached SVN archive "${_SVN_DISTFILE.${repo}:Q}"."; \
	${MKDIR} ${_SVN_DISTDIR:Q};					\
	pax -w ${SVN_MODULE.${repo}:Q} | gzip > ${_SVN_DISTDIR}/${_SVN_DISTFILE.${repo}:Q}.tmp;	\
	${MV} '${_SVN_DISTDIR}/${_SVN_DISTFILE.${repo}:Q}.tmp' '${_SVN_DISTDIR}/${_SVN_DISTFILE.${repo}:Q}'

#   fetch svn repo or update cached one
_SVN_FETCH_REPO.${repo}=	\
	if [ ! -d ${SVN_MODULE.${repo}:Q} ]; then				\
	  ${STEP_MSG} "Cloning SVN repository "${SVN_MODULE.${repo}:Q}".";	\
	  ${SETENV} ${_SVN_ENV.${repo}} ${_SVN_CMD}				\
	    checkout ${_SVN_FLAG.${repo}} ${SVN_CHECKOUT_FLAGS}			\
	    ${SVN_REPO.${repo}:Q} ${SVN_MODULE.${repo}:Q};			\
	else									\
	  ${STEP_MSG} "Updating SVN repository "${_SVN_FLAG.${repo}:Q}".";	\
	  ${SETENV} ${_SVN_ENV.${repo}} ${_SVN_CMD}				\
	    update ${_SVN_FLAG.${repo}} ${SVN_CHECKOUT_FLAGS}			\
	    ${SVN_MODULE.${repo}:Q};						\
	fi
.endfor

pre-extract: do-svn-extract

.PHONY: do-svn-extract
do-svn-extract:
.for _repo_ in ${SVN_REPOSITORIES}
.if defined(SVN_CERTS.${_repo_}) && !empty(SVN_CERTS.${_repo_})
	${RUN}${MKDIR} -p ${_SVN_CONFIG_DIR}/auth/svn.ssl.server
	${RUN}${CP} ${SVN_CERTS.${_repo_}} ${_SVN_CONFIG_DIR}/auth/svn.ssl.server
.endif
	${RUN} cd ${WRKDIR};							\
	if [ ! -d ${_SVN_DISTDIR:Q} ]; then mkdir -p ${_SVN_DISTDIR:Q}; fi;	\
	${_SVN_EXTRACT_CACHED.${_repo_}};					\
	${_SVN_FETCH_REPO.${_repo_}};						\
	${_SVN_CREATE_CACHE.${_repo_}};
.endfor

.endif
