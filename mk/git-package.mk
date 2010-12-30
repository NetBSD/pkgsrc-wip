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
USE_TOOLS+=		pax

# switch either (from scratch) clone is necessary or (already cloned) checkout is enough
_GIT_NEED_CLONE=	${WRKDIR}/.need_clone

#
# defaults for user-visible input variables
#

GIT_TAG?=		tip
GIT_MODULE?=		${PKGBASE}

DISTFILES?=		# empty
.if empty(GIT_TAG) || ${GIT_TAG} == "tip"
PKGREVISION?=		${_GIT_PKGVERSION:S/.//g}
.else
PKGREVISION?=		${GIT_TAG}
.endif

#
# Input validation
#

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
_GIT_FLAGS?=		--quiet --depth 1
_GIT_PKGVERSION_CMD=	${DATE} -u +'%Y.%m.%d'
_GIT_PKGVERSION=	${_GIT_PKGVERSION_CMD:sh}
_GIT_DISTDIR=		${DISTDIR}/git-package

_GIT_TODAY_CMD=         ${DATE} -u +'%Y-%m-%d'
_GIT_TODAY=             ${_GIT_TODAY_CMD:sh}

.for _repo_ in ${GIT_REPOSITORIES}
GIT_MODULE.${_repo_}?=    ${GIT_MODULE} #${_repo_}

## # determine appropriate checkout date or tag
## .  if defined(GIT_TAG.${repo})
## _GIT_TAG_FLAG.${repo}=  -r${GIT_TAG.${repo}}
## _GIT_TAG.${repo}=       ${GIT_TAG.${repo}}
## .  elif defined(GIT_TAG)
## _GIT_TAG_FLAG.${repo}=  -r${GIT_TAG}
## _GIT_TAG.${repo}=       ${GIT_TAG}
## .  elif defined(CHECKOUT_DATE)
## _GIT_TAG_FLAG.${repo}=  -D${CHECKOUT_DATE:Q}
## _GIT_TAG.${repo}=       ${CHECKOUT_DATE:Q}
## .  else
## _GIT_TAG_FLAG.${repo}=  '-D${_GIT_TODAY} 00:00 +0000'
_GIT_TAG.${_repo_}=       ${_GIT_TODAY:Q}
## .  endif

# Cache support:
#   cache file name (compression is not really effective)
_GIT_DISTFILE.${_repo_}=  ${GIT_MODULE.${_repo_}}-${_GIT_TAG.${_repo_}}.tar

#   command to extract cache file
_GIT_EXTRACT_CACHED.${_repo_}=    \
        if [ -f ${_GIT_DISTDIR}/${_GIT_DISTFILE.${_repo_}:Q} ]; then              \
          ${STEP_MSG} "(1) Extracting cached GIT archive "${_GIT_DISTFILE.${_repo_}:Q}"."; \
          pax -r -f ${_GIT_DISTDIR}/${_GIT_DISTFILE.${_repo_}:Q} &&  rm -f ${_GIT_NEED_CLONE}  ; \
        fi

#   create cache archive
_GIT_CREATE_CACHE.${_repo_}=      \
        ${STEP_MSG} "(4) Creating cached GIT archive "${_GIT_DISTFILE.${_repo_}:Q} "on" ${_GIT_DISTDIR:Q}"."; \
        ${MKDIR} ${_GIT_DISTDIR:Q};                                     \
        pax -w  -f ${_GIT_DISTDIR}/${_GIT_DISTFILE.${_repo_}:Q} */.git || rm -f ${_GIT_DISTDIR}/${_GIT_DISTFILE.${_repo_}:Q}
.endfor

pre-extract: do-git-extract

.PHONY: do-git-extract
do-git-extract:
.for _repo_ in ${GIT_REPOSITORIES}
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKDIR};							\
	if [ ! -d ${_GIT_DISTDIR} ]; then mkdir -p ${_GIT_DISTDIR:Q};  fi;	\
	${_GIT_EXTRACT_CACHED.${_repo_}};				\
	p="$$(cd ${_GIT_DISTDIR} && ls -t ${GIT_MODULE.${_repo_}}-[0-9-]*.tar | head -n 1)";	\
	if [ -n "$$p" ]; then						\
	    q="$$(cd ${_GIT_DISTDIR} && ls -t ${GIT_MODULE.${_repo_}}-[0-9]*.tar | wc -l)" &&	\
	    if [ $$(($$q)) -gt 3 ] ; then	    \
	       ${STEP_MSG} "(1a) more than 3 generation files found in ${_GIT_DISTDIR}, you may";	\
	       ${STEP_MSG} "	 delete them manually to avoid getting them fat --> $$p etc" ;		\
	       ${STEP_MSG} "	 suggesting to leave just any one of these," ;				\
	       ${STEP_MSG} "	 or delete them all. (But it would take time at next clone.)" ;		\
	    fi;	\
	    if [ "$$p" != ${_GIT_DISTFILE.${_repo_}:Q} ]; then		\
	      ${STEP_MSG} "(2) Extracting cached GIT archive \"""$$p\".";	\
            pax -r -f ${_GIT_DISTDIR:Q}/"$$p" &&  rm -f ${_GIT_NEED_CLONE};	\
	    fi								\
	else								\
	  touch ${_GIT_NEED_CLONE};					\
        fi;                                                             \
	if [ -r ${_GIT_NEED_CLONE} ]; then				\
        ${STEP_MSG} "(3a) git clone from "${GIT_MODULE.${_repo_}:Q}" with "${_GIT_FLAGS}"." ;	\
		${_GIT_CMD} clone					\
			${_GIT_FLAGS}		 			\
			${GIT_REPO.${_repo_}:Q};			\
	else								\
	${STEP_MSG} "(3b) git pull origin master from "${GIT_MODULE.${_repo_}:Q} "." ;	\
		(cd ${GIT_MODULE};					\
		${_GIT_CMD} pull ${GIT_FLAGS} origin master &&	 	\
		${_GIT_CMD} checkout --quiet -f master ; )		\
	fi;								\
	if [ "$$p" != ${_GIT_DISTFILE.${_repo_}:Q} ] || [ -r ${_GIT_NEED_CLONE} ]; then	\
	        ${_GIT_CREATE_CACHE.${_repo_}};				\
	else								\
         ${STEP_MSG} "(5) Skipping write cache, the same date or newly cloned";\
	fi
.endfor

.endif
#	${SETENV} ${_GIT_ENV}						\
