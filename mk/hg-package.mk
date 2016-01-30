# $Id: hg-package.mk,v 1.9 2013/02/19 10:28:14 fhajny Exp $

# This file provides simple access to Mercurial repositories, so that packages
# can be created from Mercurial instead of from released tarballs.
#
# === User-settable variables ===
#
# CHECKOUT_DATE
#	Date to check out in ISO format (YYYY-MM-DD).
#
# HG_DISTDIR
#	A directory where to store the cached repositories (default:
#	distfiles/hg-packages)
#
# === Package-settable variables ===
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

DISTFILES?=		# empty
PKGNAME?=		${DISTNAME:C,-[0-9].*,,}-hg-${_HG_PKGVERSION}
# Enforce PKGREVISION unless HG_TAG is set:
.if empty(HG_TAG)
. if defined(CHECKOUT_DATE)
PKGREVISION?=		$(CHECKOUT_DATE:S/-//g)
. else
PKGREVISION?=		$(_HG_PKGVERSION:S/.//g)
. endif
.endif

#
# definition of user-visible output variables
#

# commonly used repositories
HG_ROOT_SOURCEFORGE?=	http://${HG_PROJECT}.hg.sourceforge.net:/cvsroot/${HG_PROJECT}
HG_PROJECT?=		${PKGBASE}

#
# End of the interface part. Start of the implementation part.
#

#
# Input validation
#

.if !defined(HG_REPOSITORIES)
PKG_FAIL_REASON+=	"[hg-package.mk] HG_REPOSITORIES must be set."
HG_REPOSITORIES?=	# none
.endif

.for _repo_ in ${HG_REPOSITORIES}
.  if !defined(HG_REPO.${_repo_})
PKG_FAIL_REASON+=	"[hg-package.mk] HG_REPO."${_repo_:Q}" must be set."
.  endif
.endfor

#
# Internal variables
#

USE_TOOLS+=		date pax

_HG_CMD=		hg
_HG_ENV=		# empty
_HG_FLAGS=		-q
_HG_CONFIG_DIR=	${WRKDIR}/.hg
_HG_TODAY_CMD=		${DATE} -u +'%Y-%m-%d'
_HG_TODAY=		${_HG_TODAY_CMD:sh}
_HG_PKGVERSION_CMD=	${DATE} -u +'%Y.%m.%d'
_HG_PKGVERSION=		${_HG_PKGVERSION_CMD:sh}
HG_DISTDIR?=		${DISTDIR}/hg-packages

#
# Generation of repository-specific variables
#

.for repo in ${HG_REPOSITORIES}
HG_MODULE.${repo}?=	${repo}

# determine appropriate checkout date or tag
.  if defined(HG_TAG.${repo})
_HG_TAG_FLAG.${repo}=	-r${HG_TAG.${repo}}
_HG_TAG.${repo}=	${HG_TAG.${repo}}
.  elif defined(HG_TAG)
_HG_TAG_FLAG.${repo}=	-r${HG_TAG}
_HG_TAG.${repo}=	${HG_TAG}
.  elif defined(CHECKOUT_DATE)
_HG_TAG_FLAG.${repo}=	-d${CHECKOUT_DATE:Q}
_HG_TAG.${repo}=	${CHECKOUT_DATE:Q}
.  else
_HG_TAG_FLAG.${repo}=	-d<${_HG_TODAY} 00:00:00
_HG_TAG.${repo}=	${_HG_TODAY:Q}
.  endif

# Cache support:
#   cache file name
_HG_DISTFILE.${repo}=	${PKGBASE}-${HG_MODULE.${repo}}-${_HG_TAG.${repo}}.tar.gz

#   command to extract cache file
_HG_EXTRACT_CACHED.${repo}=	\
	if [ -f ${HG_DISTDIR}/${_HG_DISTFILE.${repo}:Q} ]; then		\
	  ${STEP_MSG} "Extracting cached Mercurial archive "${_HG_DISTFILE.${repo}:Q}"."; \
	  gzip -d -c ${HG_DISTDIR}/${_HG_DISTFILE.${repo}:Q} | pax -r;	\
	  exit 0;							\
	fi

#   create cache archive
_HG_CREATE_CACHE.${repo}=	\
	${STEP_MSG} "Creating cached Mercurial archive "${_HG_DISTFILE.${repo}:Q}"."; \
	${MKDIR} ${HG_DISTDIR:Q};					\
	pax -w ${HG_MODULE.${repo}:Q} | gzip > ${HG_DISTDIR}/${_HG_DISTFILE.${repo}:Q}
.endfor

pre-extract: do-hg-extract

.PHONY: do-hg-extract
do-hg-extract:
.for _repo_ in ${HG_REPOSITORIES}
	${RUN} cd ${WRKDIR};						\
	if [ ! -d ${HG_DISTDIR:Q} ]; then mkdir -p ${HG_DISTDIR:Q}; fi;	\
	if [ ! -d ${HG_MODULE.${_repo_}:Q}/.hg ]; then			\
		${_HG_EXTRACT_CACHED.${_repo_}};			\
		${SETENV} ${_HG_ENV}					\
		       ${_HG_CMD} clone ${_HG_FLAGS}			\
			       ${HG_REPO.${_repo_}:Q}			\
				${HG_MODULE.${_repo_}} &&		\
		(cd ${HG_MODULE.${_repo_}:Q} && 			\
		${SETENV} ${_HG_ENV}					\
			${_HG_CMD} update ${_HG_FLAGS}			\
				 ${_HG_TAG_FLAG.${_repo_}:Q}) &&	\
		${_HG_CREATE_CACHE.${_repo_}};				\
	else								\
		(cd ${HG_MODULE.${_repo_}:Q} &&				\
		${SETENV} ${_HG_ENV}					\
			${_HG_CMD} pull ${_HG_FLAGS} &&			\
		${SETENV} ${_HG_ENV}					\
			${_HG_CMD} update -C ${_HG_FLAGS})		\
	fi
.endfor

.endif
