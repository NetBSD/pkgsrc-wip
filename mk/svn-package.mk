# $Id: svn-package.mk,v 1.7 2008/12/22 16:46:08 asau Exp $

# This file provides simple access to Subversion repositories, so that packages
# can be created from Subversion instead of from released tarballs.
#
# === Package-settable variables ===
#
# A package using this file shall define the following variables:
#
# SVN_REPOSITORIES
#	A list of unique identifiers. For each of those identifiers, the
#	following variables define the details of how to access the
#	Subversion repository.
#
#	SVN_ROOT and SVN_MODULE must be defined.
#
# SVN_ROOT.${id}
#	The SVNROOT for the SVN repository, including anonsvn password,
#	if applicable.
#
# SVN_MODULE.${id}
#	The SVN module to check out.
#
# It may define the following variables:
#
# SVN_TAG
#	The SVN tag to check out (default: HEAD).
#
# SVN_CERTS
#	Files holding SSL certificates of the svn servers.
#
# SVN_TAG.${id}
#	Overridable SVN tag for a repository.
#
# === Variables defined here ===
#
# This file defines the following variables:
#
# SVN_ROOT_SOURCEFORGE
#	Common SVN repository locations for use in the SVN_ROOT
#	variables.
#
# It also provides default values for the following variables, differing
# from the system-wide defaults:
#
# DISTFILES
#	Is set to an empty list, since that is the right choice for most
#	of the Subversion packages.
#
# Keywords: subversion
#

.if !defined(_PKG_MK_SVN_PACKAGE_MK)
_PKG_MK_SVN_PACKAGE_MK=	# defined

BUILD_DEPENDS+=		subversion-base>=1.0:../../devel/subversion-base

#
# defaults for user-visible input variables
#

SVN_TAG?=		HEAD
DISTFILES?=		# empty

#
# definition of user-visible output variables
#

# commonly used repositories
SVN_ROOT_SOURCEFORGE=	https://svn.sourceforge.net/svnroot

#
# End of the interface part. Start of the implementation part.
#

#
# Input validation
#

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
# Internal variables
#

_SVN_CONFIG_DIR=	${WRKDIR}/.subversion
_SVN_RSH=		ssh
_SVN_CMD=		svn
_SVN_ENV=		# empty
_SVN_ENV+=		SVN_RSH=${_SVN_RSH:Q}
_SVN_FLAGS=		-q
_SVN_CHECKOUT_FLAGS=	--config-dir=${_SVN_CONFIG_DIR} --non-interactive

pre-extract: do-svn-extract

.PHONY: do-svn-extract
do-svn-extract:
.if defined(SVN_CERTS) && !empty(SVN_CERTS)
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} -p ${_SVN_CONFIG_DIR}/auth/svn.ssl.server
	${_PKG_SILENT}${_PKG_DEBUG}${CP} ${SVN_CERTS:Q} ${_SVN_CONFIG_DIR}/auth/svn.ssl.server
.endif
.for _repo_ in ${SVN_REPOSITORIES}
	${RUN} cd ${WRKDIR};						\
	${SETENV} ${_SVN_ENV}						\
		${_SVN_CMD} checkout ${_SVN_CHECKOUT_FLAGS}		\
			-r ${SVN_TAG.${_repo_}:Q}			\
			${_SVN_FLAGS}		 			\
			${SVN_ROOT.${_repo_}:Q}				\
			${SVN_MODULE.${_repo_}:Q}
.endfor

.endif
