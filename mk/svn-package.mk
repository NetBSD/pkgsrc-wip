# $Id: svn-package.mk,v 1.3 2007/01/27 15:33:09 dillo Exp $

# This file provides simple access to Subversion repositories, so that packages
# can be created from Subversion instead of from released tarballs.
#
# A package using this file shall define the following variables:
#
#	SVN_REPOSITORIES
#		A list of unique identifiers /id/ for which appropriate
#		SVN_ROOT and SVN_MODULE must be defined.
#
#	SVN_ROOT.${id}
#		The SVNROOT for the SVN repository, including anonsvn
#		password, if applicable.
#
#	SVN_MODULE.${id}
#		The SVN module to check out.
#
# It may define the following variables:
#
#	SVN_TAG
#		The SVN tag to check out (default: HEAD).
#
#	SVN_CERTS
#		Files holding SSL certificates of the svn servers.
#
#	SVN_TAG.${id}
#		Overridable SVN tag for a repository.
#
# This file defines the following variables:
#
#	SVN_ROOT_SOURCEFORGE
#		Common SVN repository locations for use in the SVN_ROOT
#		variables.

.if !defined(_PKG_MK_SVN_PACKAGE_MK)
_PKG_MK_SVN_PACKAGE_MK=	# defined

DEPENDS+=		subversion-base>=1.0:../../devel/subversion-base

#
# defaults for user-visible input variables
#

SVN_TAG?=		HEAD
DISTFILES?=		# empty

.if !defined(SVN_REPOSITORIES)
PKG_FAIL_REASON+=	"[svn-package.mk] SVN_REPOSITORIES must be set."
SVN_REPOSITORIES?=	# none
.endif

.for _repo_ in ${SVN_REPOSITORIES}
.  if !defined(SVN_ROOT.${_repo_})
PKG_FAIL_REASON+=	"[svn-package.mk] SVN_ROOT."${_repo_:Q}" must be set."
.  endif
.  if !defined(SVN_MODULE.${_repo_})
PKG_FAIL_REASON+=	"[svn-package.mk] SVN_MODULE."${_repo_:Q}" must be set."
.  endif
SVN_TAG.${_repo_}?=	${SVN_TAG}
.endfor

#
# definition of user-visible output variables
#

# commonly used repositories
SVN_ROOT_SOURCEFORGE=	https://svn.sourceforge.net/svnroot

#
# Internal variables
#

_SVN_CONFIG_DIR=	${WRKDIR}/.subversion
_SVN_RSH=		ssh
_SVN_CMD=		svn
_SVN_ENV=		# empty
_SVN_ENV+=		SVN_RSH=${_SVN_RSH:Q}
_SVN_FLAGS=		-q
_SVN_CHECKOUT_FLAGS=	--config-dir=${_SVN_CONFIG_DIR} --non-interactive -r ${SVN_TAG:Q}

pre-extract: do-svn-extract

.PHONY: do-svn-extract
do-svn-extract:
.if defined(SVN_CERTS) && !empty(SVN_CERTS)
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} -p ${_SVN_CONFIG_DIR}/auth/svn.ssl.server
	${_PKG_SILENT}${_PKG_DEBUG}${CP} ${SVN_CERTS:Q} ${_SVN_CONFIG_DIR}/auth/svn.ssl.server
.endif
.for _repo_ in ${SVN_REPOSITORIES}
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKDIR};							\
	${SETENV} ${_SVN_ENV}						\
		${_SVN_CMD} checkout ${_SVN_CHECKOUT_FLAGS}		\
			${_SVN_FLAGS}		 			\
			${SVN_ROOT.${_repo_}:Q}				\
			${SVN_MODULE.${_repo_}:Q}
.endfor

.endif
