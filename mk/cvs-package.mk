# $Id: cvs-package.mk,v 1.9 2006/01/30 01:18:15 lsed Exp $

# Written by:
#     Roland Illig <roland.illig@gmx.de>, 2004.
#
# A package using this file shall define the following variables:
#     CVS_REPOSITORIES: 	A list of unique identifiers /id/ for which
#				appropriate CVS_ROOT and CVS_MODULE must be
#				defined.
#     CVS_ROOT.${id}:		the CVSROOT for the CVS repository, including
#				anoncvs password
#     CVS_MODULE.${id}:		the CVS module to check out
#
# It may define the following variable:
#     CVS_TAG:		the CVS tag to check out (default: HEAD)
#
# After inclusion of this file, the following variables are defined:
#     CVS_ROOT_GNU
#     CVS_ROOT_NONGNU
#     CVS_ROOT_SOURCEFORGE

.if !defined(_PKG_MK_CVS_PACKAGE_MK)
_PKG_MK_CVS_PACKAGE_MK=	# defined

#
# defaults for user-visible input variables
#

CVS_TAG?=		HEAD
DISTFILES?=		# empty

#
# definition of user-visible output variables
#

# commonly used repositories
CVS_ROOT_GNU=		:ext:anoncvs@cvs.gnu.org:/cvsroot
CVS_ROOT_NONGNU=	${CVS_ROOT_GNU}
CVS_ROOT_SOURCEFORGE=	:pserver:anonymous:@cvs.sourceforge.net:/cvsroot

#
# defaults for internal variables
#

_CVS_RSH=		ssh
_CVS_CMD=		cvs
_CVS_ENV=		CVS_PASSFILE=${_CVS_PASSFILE:Q}
_CVS_ENV+=		CVS_RSH=${_CVS_RSH:Q}
_CVS_FLAGS=		-Q
_CVS_CHECKOUT_FLAGS=	-P -r ${CVS_TAG:Q}
_CVS_PASSFILE=		${WRKDIR}/.cvs_passwords

.if !defined(CVS_REPOSITORIES)
PKG_FAIL_REASON+=	"[cvs-package.mk] CVS_REPOSITORIES must be set."
.endif

pre-extract: do-cvs-extract

.PHONY: do-cvs-extract
do-cvs-extract:
.for _repo_ in ${CVS_REPOSITORIES}
.  if !defined(CVS_ROOT.${_repo_})
PKG_FAIL_REASON+=	"[cvs-package.mk] CVS_ROOT.${_repo_} must be set."
.  elif !defined(CVS_MODULE.${_repo_})
PKG_FAIL_REASON+=	"[cvs-package.mk] CVS_MODULE.${_repo_} must be set."
.  endif
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKDIR};							\
	case ${CVS_ROOT.${_repo_}:Q} in					\
	  :pserver:*)							\
	    if ${TEST} ! -f "${_CVS_PASSFILE}"; then			\
	      ${TOUCH} "${_CVS_PASSFILE}";				\
	    fi;								\
	    ${SETENV} ${_CVS_ENV} ${_CVS_CMD} ${_CVS_FLAGS} 		\
		-d ${CVS_ROOT.${_repo_}:Q} login			\
	  ;;								\
	  *) ;;								\
	esac;								\
	${SETENV} ${_CVS_ENV} ${_CVS_CMD} ${_CVS_FLAGS}			\
		-d ${CVS_ROOT.${_repo_}:Q} checkout 			\
		${_CVS_CHECKOUT_FLAGS} -d ${_repo_} ${CVS_MODULE.${_repo_}}
.endfor

.endif
