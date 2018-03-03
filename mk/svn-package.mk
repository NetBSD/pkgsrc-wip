# $NetBSD$
#
# This file provides simple access to Subversion repositories, so that
# packages can be created from Subversion instead of from released
# tarballs. Whenever a package is fetched from Subversion, an archive
# is created from it and saved below ${DISTDIR}, to save bandwidth.
#
# User-settable variables:
#
# CHECKOUT_DATE (optional)
#	Date to check out in ISO format (YYYY-MM-DD).
#
#	When a package doesn't specify a CVS_TAG, it is checked out from
#	the HEAD revision, and the PKGREVISION is set based on the date.
#	To keep this date stable during a bulk build (which may span
#	one or more midnights), this can be set to a fixed date.
#
# Package-settable variables:
#
# SVN_REPO (required)
#	The URL of the Subversion repository.
#
#	Example: https://svn.code.sf.net/p/projectname/code/trunk
#
# SVN_MODULE (optional)
#	The directory where the files are extracted, relative to WRKDIR.
#
# SVN_REVISION (optional)
#	The revision to check out.
#
#	Example: 12345
#
# SVN_REPOSITORIES (optional)
#	If the package needs multiple Subversion repositories, this
#	is the list of repository IDs. For each of these repositories,
#	parameterized variants of the above variables are defined.
#
#	Example:
#	SVN_REPOSITORIES=	stable latest
#	SVN_REPO.stable=	https://svn.code.sf.net/p/project/code/tag/1.0.0
#	SVN_MODULE.stable=	stable
#	SVN_REPO.latest=	https://svn.code.sf.net/p/project/code/trunk
#	SVN_MODULE.latest=	latest
#
# Keywords: svn subversion

BUILD_DEPENDS+=		subversion-base-[0-9]*:../../devel/subversion-base

# Defaults for package-settable variables
DISTFILES?=		# empty
.if defined(CHECKOUT_DATE)
PKGREVISION?=		${CHECKOUT_DATE:S/-//g}
.else
PKGREVISION?=		${_SVN_PKGREVISION_CMD:sh}
.endif

# The common case of a single repository
.if defined(SVN_REPO)
SVN_MODULE?=		${SVN_REPO:S,/$,,:S,/trunk$,,:S,/code$,,:T}
SVN_REPOSITORIES+=	_default
SVN_REPO._default=	${SVN_REPO}
SVN_MODULE._default=	${SVN_MODULE}
WRKSRC?=		${WRKDIR}/${SVN_MODULE}
.endif

SVN_REPOSITORIES?=	# none
.if empty(SVN_REPOSITORIES)
PKG_FAIL_REASON+=	"[svn-package.mk] SVN_REPOSITORIES must be set."
.endif

.for repo in ${SVN_REPOSITORIES}
.  if empty(SVN_REPO.${repo})
PKG_FAIL_REASON+=	"[svn-package.mk] SVN_REPO."${repo:Q}" must be set."
.  endif
.endfor

USE_TOOLS+=		date pax

_SVN_CMD=		svn
_SVN_CONFIG_DIR=	${WRKDIR}/.subversion
_SVN_CHECKOUT_FLAGS=	--config-dir=${_SVN_CONFIG_DIR} --non-interactive
_SVN_PKGREVISION_CMD=	${DATE} -u +'%Y%m%d'
_SVN_DISTDIR=		${DISTDIR}/svn-packages

# Definition of repository-specific variables
.for repo in ${SVN_REPOSITORIES}
SVN_MODULE.${repo}?=	${repo}
.  if defined(CHECKOUT_DATE)
SVN_REVISION.${repo}?=	{${CHECKOUT_DATE}}
.  else
SVN_REVISION.${repo}?=	HEAD
.  endif

# The cached archive
_SVN_DISTFILE.${repo}=	${PKGBASE}-${SVN_MODULE.${repo}}-svnarchive.tar.gz

# Define the shell variables used by the following commands
_SVN_CMD.vars.${repo}= \
	repo=${SVN_REPO.${repo}:Q}; \
	module=${SVN_MODULE.${repo}:Q}; \
	archive=${_SVN_DISTDIR}/${_SVN_DISTFILE.${repo}:Q}; \
	revision=${SVN_REVISION.${repo}:Q}

# Extract the cached archive
_SVN_CMD.extract_archive.${repo}= \
	if [ -f "$$archive" ]; then					\
	  ${STEP_MSG} "Extracting cached Subversion archive $${archive\#\#*/}."; \
	  gzip -d -c "$$archive" | pax -r;				\
	fi

# Install client certificates for authentication
.if !empty(SVN_CERTS.${repo})
_SVN_CMD.install_certs.${repo}= \
	${MKDIR} ${_SVN_CONFIG_DIR}/auth/svn.ssl.server;		\
	${CP} ${SVN_CERTS.${repo}} ${_SVN_CONFIG_DIR}/auth/svn.ssl.server
.else
_SVN_CMD.install_certs.${repo}= \
	${DO_NADA}
.endif

# Check out the repository or update the cached one
_SVN_CMD.fetch_repo.${repo}= \
	if [ ! -d "$$module" ]; then			\
	  ${STEP_MSG} "Checking out Subversion repository $$repo.";	\
	  ${_SVN_CMD} checkout -r "$$revision" ${SVN_CHECKOUT_FLAGS}	\
	    "$$repo" "$$module";					\
	else								\
	  ${STEP_MSG} "Updating Subversion repository $$repo.";		\
	  ${_SVN_CMD} update -r "$$revision" ${SVN_CHECKOUT_FLAGS} "$$module"; \
	fi

# Create the cached archive from the checked out repository
_SVN_CMD.create_archive.${repo}= \
	${STEP_MSG} "Creating cached Subversion archive $${archive\#\#*/}."; \
	${MKDIR} "$${archive%/*}";					\
	pax -w "$$module" | gzip > "$$archive.tmp";			\
	${MV} "$$archive.tmp" "$$archive"
.endfor

pre-extract: do-svn-extract

do-svn-extract: .PHONY
.for repo in ${SVN_REPOSITORIES}
	${RUN} \
	cd ${WRKDIR}; \
	${_SVN_CMD.vars.${repo}}; \
	${_SVN_CMD.install_certs.${repo}}; \
	${_SVN_CMD.extract_archive.${repo}}; \
	${_SVN_CMD.fetch_repo.${repo}}; \
	${_SVN_CMD.create_archive.${repo}}
.endfor

# Debug info for show-all and show-all-svn
_VARGROUPS+=	svn
_PKG_VARS.svn+=	SVN_REPO SVN_REVISION SVN_REPOSITORIES
_SYS_VARS.svn+=	DISTFILES PKGREVISION
_SYS_VARS.svn+=	_SVN_DISTDIR
.for repo in ${SVN_REPOSITORIES}
.  for varbase in SVN_REPO SVN_MODULE SVN_REVISION SVN_CERTS
_PKG_VARS.svn+=	${varbase}.${repo}
.  endfor
.  for varbase in _SVN_DISTFILE
_SYS_VARS.svn+=	${varbase}.${repo}
.  endfor
.endfor
