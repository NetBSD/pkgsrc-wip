# $Id: hg-package.mk,v 1.3 2011/06/26 21:35:30 asau Exp $

# This file provides simple access to Mercurial repositories, so that packages
# can be created from Mercurial instead of from released tarballs.
#
# === User-settable variables ===
#
# CHECKOUT_DATE
#	Date to check out in ISO format (YYYY-MM-DD).
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

HG_TAG?=		tip

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
_HG_DISTDIR=		${DISTDIR}/hg-packages

#
# Generation of repository-specific variables
#

.for repo in ${HG_REPOSITORIES}

# determine appropriate checkout date or tag
.  if defined(HG_TAG.${repo})
_HG_TAG_FLAG.${repo}=	-r${HG_TAG.${repo}}
_HG_TAG.${repo}=	${HG_TAG.${repo}}
.  elif defined(HG_TAG)
_HG_TAG_FLAG.${repo}=	-r${HG_TAG}
_HG_TAG.${repo}=	${HG_TAG}
.  elif defined(CHECKOUT_DATE)
# _CVS_TAG_FLAG.${repo}=	-D${CHECKOUT_DATE:Q}
# _CVS_TAG.${repo}=	${CHECKOUT_DATE:Q}
.  else
# _CVS_TAG_FLAG.${repo}=	'-D${_CVS_TODAY} 00:00 +0000'
# _CVS_TAG.${repo}=	${_CVS_TODAY:Q}
.  endif

.endfor

pre-extract: do-hg-extract

.PHONY: do-hg-extract
do-hg-extract:
.for _repo_ in ${HG_REPOSITORIES}
	${RUN} cd ${WRKDIR};						\
	${SETENV} ${_HG_ENV}						\
		${_HG_CMD} clone					\
			${_HG_TAG_FLAG.${repo}:Q}			\
			${_HG_FLAGS}		 			\
			${HG_REPO.${_repo_}:Q}
.endfor

.endif
