# $NetBSD: cvs-package.mk,v 1.3 2005/01/11 18:42:30 rillig Exp $

# Written by:
#    Roland Illig <roland.illig@gmx.de>, 2004.
#
# A package using this file shall define the following variables:
# CVS_REPOSITORY:	the CVS repository, including anoncvs password
# CVS_MODULE:		the CVS module to check out
#
# It can use the following predefined variables:
#
# CVS_REPOSITORY_GNU
# CVS_REPOSITORY_NONGNU
# CVS_REPOSITORY_SOURCEFORGE

.if !defined(_PKG_MK_CVS_PACKAGE_MK)
_PKG_MK_CVS_PACKAGE_MK=	# defined

# commonly used repositories
CVS_REPOSITORY_GNU=	:ext:anoncvs@cvs.gnu.org:/cvsroot
CVS_REPOSITORY_NONGNU=	${CVS_REPOSITORY_GNU}
CVS_REPOSITORY_SOURCEFORGE= :pserver:anonymous:@cvs.sourceforge.net:/cvsroot

# default values (internal)
_CVS_RSH=		ssh
_CVS_CMD=		cvs
_CVS_ENV=		CVS_PASSFILE="${_CVS_PASSFILE}"
_CVS_ENV+=		CVS_RSH="${_CVS_RSH}"
_CVS_ENV+=		CVSROOT="${_CVS_ROOT}"
_CVS_FLAGS=		-Q
_CVS_CHECKOUT_FLAGS=	-P -d ${DISTNAME}
_CVS_PASSFILE=		${WRKDIR}/.cvspass
.if !defined(CVS_REPOSITORY)
PKG_FAIL_REASON=	"No CVS repository specified."
.elif !defined(CVS_MODULE)
PKG_FAIL_REASON=	"No CVS module specified."
.else
_CVS_ROOT=		${CVS_REPOSITORY}
_CVS_MODULE=		${CVS_MODULE}
.endif

# default values (public)
DISTFILES?=		# empty
NO_FETCH?=		yes

do-extract:
	${_PKG_DEBUG}${_PKG_SILENT}set -e;				\
	cd ${WRKDIR};							\
	case "${CVS_REPOSITORY}" in					\
	  :pserver:*)							\
	    if ${TEST} ! -f "${_CVS_PASSFILE}"; then			\
	      ${TOUCH} "${_CVS_PASSFILE}";				\
	    fi;								\
	    ${ENV} ${_CVS_ENV} ${_CVS_CMD} ${_CVS_FLAGS} login;;	\
	  *) ;;								\
	esac;								\
	${ENV} ${_CVS_ENV} ${_CVS_CMD} ${_CVS_FLAGS} checkout ${_CVS_CHECKOUT_FLAGS} ${_CVS_MODULE}

.endif
