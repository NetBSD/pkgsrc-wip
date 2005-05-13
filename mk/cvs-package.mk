# $NetBSD: cvs-package.mk,v 1.4 2005/05/13 23:18:38 rillig Exp $

# Written by:
#     Roland Illig <roland.illig@gmx.de>, 2004.
#
# A package using this file shall define the following variables:
#     CVS_REPOSITORY:	the CVS repository, including anoncvs password
#     CVS_MODULE:	the CVS module to check out
#
# It may define the following variable:
#     CVS_TAG:		the CVS tag to check out (default: HEAD)
#
# After inclusion of this file, the following variables are defined:
#     CVS_REPOSITORY_GNU
#     CVS_REPOSITORY_NONGNU
#     CVS_REPOSITORY_SOURCEFORGE

.if !defined(_PKG_MK_CVS_PACKAGE_MK)
_PKG_MK_CVS_PACKAGE_MK=	# defined

#
# defaults for user-visible input variables
#

CVS_TAG?=		HEAD
DISTFILES?=		# empty
NO_FETCH?=		yes

#
# definition of user-visible output variables
#

# commonly used repositories
CVS_REPOSITORY_GNU=	:ext:anoncvs@cvs.gnu.org:/cvsroot
CVS_REPOSITORY_NONGNU=	${CVS_REPOSITORY_GNU}
CVS_REPOSITORY_SOURCEFORGE= :pserver:anonymous:@cvs.sourceforge.net:/cvsroot

#
# defaults for internal variables
#

_CVS_RSH=		ssh
_CVS_CMD=		cvs
_CVS_ENV=		CVS_PASSFILE=${_CVS_PASSFILE:Q}
_CVS_ENV+=		CVS_RSH=${_CVS_RSH:Q}
_CVS_ENV+=		CVSROOT=${CVS_REPOSITORY:Q}
_CVS_FLAGS=		-Q
_CVS_CHECKOUT_FLAGS=	-P -d ${DISTNAME:Q} -r ${CVS_TAG:Q}
_CVS_PASSFILE=		${WRKDIR}/.cvs_passwords
.if !defined(CVS_REPOSITORY)
PKG_FAIL_REASON=	"No CVS repository specified."
.elif !defined(CVS_MODULE)
PKG_FAIL_REASON=	"No CVS module specified."
.else
.endif

do-extract:
	${_PKG_DEBUG}${_PKG_SILENT}set -e;				\
	cd ${WRKDIR};							\
	case ${CVS_REPOSITORY:Q} in					\
	  :pserver:*)							\
	    if ${TEST} ! -f "${_CVS_PASSFILE}"; then			\
	      ${TOUCH} "${_CVS_PASSFILE}";				\
	    fi;								\
	    ${SETENV} ${_CVS_ENV} ${_CVS_CMD} ${_CVS_FLAGS} login;;	\
	  *) ;;								\
	esac;								\
	${SETENV} ${_CVS_ENV} ${_CVS_CMD} ${_CVS_FLAGS} checkout ${_CVS_CHECKOUT_FLAGS} ${CVS_MODULE}

.endif
