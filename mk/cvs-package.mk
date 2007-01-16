# $Id: cvs-package.mk,v 1.18 2007/01/16 10:35:35 rillig Exp $

# This file provides simple access to CVS repositories, so that packages
# can be created from CVS instead of from released tarballs.
#
# A package using this file shall define the following variables:
#
#	CVS_REPOSITORIES
#		A list of unique identifiers /id/ for which appropriate
#		CVS_ROOT and CVS_MODULE must be defined.
#
#	CVS_ROOT.${id}
#		The CVSROOT for the CVS repository, including anoncvs
#		password, if applicable.
#
#	CVS_MODULE.${id}
#		The CVS module to check out.
#
# It may define the following variables:
#
#	CVS_TAG
#		The CVS tag to check out (default: today at midnight).
#
#	CVS_TAG.${id}
#		Overridable CVS tag for a repository.
#
# This file defines the following variables:
#
#	CVS_ROOT_GNU
#	CVS_ROOT_NONGNU
#	CVS_ROOT_SOURCEFORGE
#		Common CVS repository locations for use in the CVS_ROOT
#		variables.

.if !defined(_PKG_MK_CVS_PACKAGE_MK)
_PKG_MK_CVS_PACKAGE_MK=	# defined

#
# defaults for user-visible input variables
#

DISTFILES?=		# empty

#
# definition of user-visible output variables
#

# commonly used repositories
CVS_ROOT_GNU=		:pserver:anonymous:@cvs.savannah.gnu.org:/sources
CVS_ROOT_NONGNU=	${CVS_ROOT_GNU}
CVS_ROOT_SOURCEFORGE=	:pserver:anonymous:@%PROJECT%.cvs.sourceforge.net:/cvsroot/%PROJECT%

#
# End of the interface part. Start of the implementation part.
#

#
# Input validation
#

.if !defined(CVS_REPOSITORIES)
PKG_FAIL_REASON+=	"[cvs-package.mk] CVS_REPOSITORIES must be set."
CVS_REPOSITORIES?=	# none
.endif

.for _repo_ in ${CVS_REPOSITORIES}
.  if !defined(CVS_ROOT.${_repo_})
PKG_FAIL_REASON+=	"[cvs-package.mk] CVS_ROOT."${_repo_:Q}" must be set."
.  endif
.  if !defined(CVS_MODULE.${_repo_})
PKG_FAIL_REASON+=	"[cvs-package.mk] CVS_MODULE."${_repo_:Q}" must be set."
.  endif
.endfor

#
# Internal variables
#

USE_TOOLS+=		date

_CVS_RSH=		ssh
_CVS_CMD=		cvs
_CVS_ENV=		# empty
_CVS_ENV+=		CVS_PASSFILE=${_CVS_PASSFILE:Q}
_CVS_ENV+=		CVS_RSH=${_CVS_RSH:Q}
_CVS_FLAGS=		-Q
_CVS_CHECKOUT_FLAGS=	-P
_CVS_PASSFILE=		${WRKDIR}/.cvs_passwords
_CVS_TODAY_CMD=		${DATE} -u +'%Y-%m-%d'
_CVS_TODAY=		${_CVS_TODAY_CMD:sh}
_CVS_DISTDIR=		${DISTDIR}/cvs-packages

#
# Generation of repository-specific variables
#

.for _repo_ in ${CVS_REPOSITORIES}
.  if defined(CVS_TAG.${_repo_})
_CVS_TAG_FLAG.${_repo_}=	-r${CVS_TAG.${_repo_}}
_CVS_TAG.${_repo_}=		${CVS_TAG.${_repo_}}
.  elif defined(CVS_TAG)
_CVS_TAG_FLAG.${_repo_}=	-r${CVS_TAG}
_CVS_TAG.${_repo_}=		${CVS_TAG}
.  else
_CVS_TAG_FLAG.${_repo_}=	-D${_CVS_TODAY}T00:00+0
_CVS_TAG.${_repo_}=		${_CVS_TODAY:Q}
.  endif
_CVS_DISTFILE.${_repo_}=	${PKGBASE}-${CVS_MODULE.${_repo_}}-${_CVS_TAG.${_repo_}}.tar.gz
.endfor

pre-extract: do-cvs-extract

.PHONY: do-cvs-extract
do-cvs-extract:
.for _repo_ in ${CVS_REPOSITORIES}
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKDIR};							\
	if ${TEST} -f ${_CVS_DISTDIR}/${_CVS_DISTFILE.${_repo_}:Q}; then \
	  ${STEP_MSG} "Extracting cached CVS archive "${_CVS_DISTFILE.${_repo_}:Q}"."; \
	  ${PAX} -r -z -f ${_CVS_DISTDIR}/${_CVS_DISTFILE.${_repo_}:Q}; \
	else								\
	case ${CVS_ROOT.${_repo_}:Q} in					\
	  :pserver:*)							\
	    if ${TEST} ! -f ${_CVS_PASSFILE:Q}; then			\
	      ${TOUCH} ${_CVS_PASSFILE:Q};				\
	    fi;								\
	    ${STEP_MSG} "Logging in to "${CVS_ROOT.${_repo_}:Q}".";	\
	    ${SETENV} ${_CVS_ENV} ${_CVS_CMD} ${_CVS_FLAGS} 		\
		-d ${CVS_ROOT.${_repo_}:Q} login			\
	  ;;								\
	  *) ;;								\
	esac;								\
	${STEP_MSG} "Downloading "${CVS_MODULE.${_repo_}:Q}" from "${CVS_ROOT.${_repo_}:Q}"."; \
	${SETENV} ${_CVS_ENV}						\
	  ${_CVS_CMD} ${_CVS_FLAGS} -d ${CVS_ROOT.${_repo_}:Q}		\
	    checkout ${_CVS_CHECKOUT_FLAGS} ${_CVS_TAG_FLAG.${_repo_}:Q} \
	      -d ${_repo_:Q} ${CVS_MODULE.${_repo_}:Q};			\
	${STEP_MSG} "Creating cached CVS archive "${_CVS_DISTFILE.${_repo_}:Q}"."; \
	${MKDIR} ${_CVS_DISTDIR:Q};					\
	${PAX} -w -z -f ${_CVS_DISTDIR}/${_CVS_DISTFILE.${_repo_}:Q} ${_repo_:Q}; \
	fi
.endfor

.endif
