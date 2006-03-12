# $Id: cvs-package.mk,v 1.11 2006/03/12 15:37:29 rillig Exp $

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
#		The CVS tag to check out (default: HEAD).
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

CVS_TAG?=		HEAD
DISTFILES?=		# empty

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
CVS_TAG.${_repo_}?=	${CVS_TAG}
.endfor

#
# definition of user-visible output variables
#

# commonly used repositories
CVS_ROOT_GNU=		:ext:anoncvs@cvs.gnu.org:/cvsroot
CVS_ROOT_NONGNU=	${CVS_ROOT_GNU}
CVS_ROOT_SOURCEFORGE=	:pserver:anonymous:@cvs.sourceforge.net:/cvsroot

#
# Internal variables
#

_CVS_RSH=		ssh
_CVS_CMD=		cvs
_CVS_ENV=		# empty
_CVS_ENV+=		CVS_PASSFILE=${_CVS_PASSFILE:Q}
_CVS_ENV+=		CVS_RSH=${_CVS_RSH:Q}
_CVS_FLAGS=		-Q
_CVS_CHECKOUT_FLAGS=	-P -r ${CVS_TAG:Q}
_CVS_PASSFILE=		${WRKDIR}/.cvs_passwords

pre-extract: do-cvs-extract

.PHONY: do-cvs-extract
do-cvs-extract:
.for _repo_ in ${CVS_REPOSITORIES}
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKDIR};							\
	case ${CVS_ROOT.${_repo_}:Q} in					\
	  :pserver:*)							\
	    if ${TEST} ! -f ${_CVS_PASSFILE:Q}; then			\
	      ${TOUCH} ${_CVS_PASSFILE:Q};				\
	    fi;								\
	    ${SETENV} ${_CVS_ENV} ${_CVS_CMD} ${_CVS_FLAGS} 		\
		-d ${CVS_ROOT.${_repo_}:Q} login			\
	  ;;								\
	  *) ;;								\
	esac;								\
	${SETENV} ${_CVS_ENV}						\
		${_CVS_CMD} ${_CVS_FLAGS} -d ${CVS_ROOT.${_repo_}:Q}	\
			checkout ${_CVS_CHECKOUT_FLAGS}			\
			-d ${_repo_:Q} ${CVS_MODULE.${_repo_}:Q}
.endfor

.endif
