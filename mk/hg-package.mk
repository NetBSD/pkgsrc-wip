# $NetBSD$
#
# This file provides simple access to Mercurial repositories, so that packages
# can be created from Mercurial instead of from released tarballs.
#
# User-settable variables:
#
# CHECKOUT_DATE (optional)
#	Date to check out in ISO format (YYYY-MM-DD).
#
#	When a package doesn't specify a HG_TAG, it is checked out from
#	the HEAD revision, and the PKGREVISION is set based on the date.
#	To keep this date stable during a bulk build (which may span
#	one or more midnights), this can be set to a fixed date.
#
# Package-settable variables:
#
# HG_REPO (required)
#	The Mercurial repository URL.
#
#	Example: https://hg.mozilla.org/projects/nspr
#
# HG_TAG (optional)
#	The Mercurial tag to check out.
#
#	Default: HEAD
#
# If a package needs to checkout from more than one Mercurial repository,
# the setup is a little more complicated, using parameterized variants of
# the above variables.
#
# HG_REPOSITORIES (required)
#	If the package needs multiple Mercurial repositories, this
#	is the list of repository IDs. For each of these repositories,
#	parameterized variants of the above variables are defined.
#
#	Example:
#	HG_REPOSITORIES=	stable latest
#	HG_REPO.stable=		https://hg.mozilla.org/projects/nspr
#	HG_TAG.stable=		v1.2.3
#	HG_REPO.latest=		https://hg.mozilla.org/projects/nspr
#
# Keywords: hg mercurial

BUILD_DEPENDS+=		${PYPKGPREFIX}-mercurial>=0.9:../../devel/py-mercurial

# Defaults for package-settable variables
DISTFILES?=		# empty
PKGNAME?=		${DISTNAME:C,-[0-9].*,,}-hg-${_HG_PKGVERSION}
.if empty(HG_TAG)
.  if defined(CHECKOUT_DATE)
PKGREVISION?=		${CHECKOUT_DATE:S/-//g}
.  else
PKGREVISION?=		${_HG_PKGVERSION:S/.//g}
.  endif
.endif

# The common case of a single repository
.if defined(HG_REPO)
HG_EXTRACTDIR?=		${HG_REPO:S,/$,,:T}
HG_REPOSITORIES+=	default
HG_REPO.default=	${HG_REPO}
HG_EXTRACTDIR.default=	${HG_EXTRACTDIR}
WRKSRC?=		${WRKDIR}/${HG_EXTRACTDIR}
.endif

HG_REPOSITORIES?=	# none
.if empty(HG_REPOSITORIES)
PKG_FAIL_REASON+=	"[hg-package.mk] HG_REPOSITORIES must be set."
.endif

.for repo in ${HG_REPOSITORIES}
.  if empty(HG_REPO.${repo})
WARNINGS+=		"[hg-package.mk] HG_REPO."${repo:Q}" must be set."
.  endif
.  if defined(HG_MODULE.${repo}) # To be removed after 2019-01-01
WARNINGS+=		"[hg-package.mk] HG_MODULE is obsolete; use HG_EXTRACTDIR.${repo} instead."
HG_EXTRACTDIR.${repo}?=	${HG_MODULE.${repo}}
.  endif
.endfor

USE_TOOLS+=		date gzip pax

_HG_CMD=		${PREFIX}/bin/hg
_HG_FLAGS=		-q
_HG_CONFIG_DIR=		${WRKDIR}/.hg
_HG_TODAY_CMD=		${DATE} -u +'%Y-%m-%d'
_HG_TODAY=		${_HG_TODAY_CMD:sh}
_HG_PKGVERSION_CMD=	${DATE} -u +'%Y.%m.%d'
_HG_PKGVERSION=		${_HG_PKGVERSION_CMD:sh}
_HG_DISTDIR?=		${DISTDIR}/hg-packages

#
# Generation of repository-specific variables
#

.for repo in ${HG_REPOSITORIES}
HG_EXTRACTDIR.${repo}?=	${repo}

# determine appropriate checkout date or tag
.  if defined(HG_TAG.${repo})
_HG_TAG_FLAG.${repo}=	-r${HG_TAG.${repo}}
_HG_TAG.${repo}=	${HG_TAG.${repo}}
.  elif defined(HG_TAG)
_HG_TAG_FLAG.${repo}=	-r${HG_TAG}
_HG_TAG.${repo}=	${HG_TAG}
.  elif defined(CHECKOUT_DATE)
_HG_TAG_FLAG.${repo}=	-d<${CHECKOUT_DATE:Q}
_HG_TAG.${repo}=	${CHECKOUT_DATE:Q}
.  else
_HG_TAG_FLAG.${repo}=	-d<${_HG_TODAY} 00:00:00
_HG_TAG.${repo}=	${_HG_TODAY:Q}
.  endif

# Cache support:
#   cache file name
_HG_DISTFILE.${repo}=	${PKGBASE}-${repo}-${_HG_TAG.${repo}}.tar.gz

# Define the shell variables used by the following commands
_HG_CMD.vars.${repo}= \
	repo=${HG_REPO.${repo}:Q};					\
	extractdir=${HG_EXTRACTDIR.${repo}:Q};				\
	archive=${_HG_DISTDIR}/${_HG_DISTFILE.${repo}:Q}

# Extract the cached archive
_HG_CMD.extract_archive.${repo}= \
	if [ -f "$$archive" ]; then					\
	  ${STEP_MSG} "Extracting cached Mercurial archive $${archive\#\#*/}."; \
	  gzip -d -c "$$archive" | pax -r;				\
	  exit 0;							\
	fi

_HG_CMD.checkout.${repo}= \
	${STEP_MSG} "Checking out $$extractdir from $$repo.";		\
	${_HG_CMD} clone ${_HG_FLAGS} "$$repo" "$$extractdir";		\
	${_HG_CMD} --cwd "$$extractdir" update ${_HG_FLAGS} ${_HG_TAG_FLAG.${repo}:Q}

# Create the cached archive from the checked out repository
_HG_CMD.create_archive.${repo}= \
	${STEP_MSG} "Creating cached Mercurial archive $${archive\#\#*/}."; \
	${MKDIR} "$${archive%/*}";					\
	pax -w "$$extractdir" | gzip > "$$archive.tmp";			\
	${MV} "$$archive.tmp" "$$archive"
.endfor

hg-cleandir: .PHONY
.for repo in ${HG_REPOSITORIES}
	${RUN} cd ${WRKDIR};						\
	if [ -d ${HG_EXTRACTDIR.${repo}:Q} ]; then			\
		cd ${HG_EXTRACTDIR.${repo}:Q} && rm -rf *;		\
	fi
.endfor
	${RUN} cd ${WRKDIR} && rm -f .*_done && rm -rf .cwrapper

pre-extract: do-hg-extract

do-hg-extract: .PHONY
.for repo in ${HG_REPOSITORIES}
	${RUN}								\
	cd ${WRKDIR};							\
	${_HG_CMD.vars.${repo}};					\
	if [ ! -d "$$extractdir/.hg" ]; then				\
		${_HG_CMD.extract_archive.${repo}};			\
		${_HG_CMD.checkout.${repo}};				\
		${_HG_CMD.create_archive.${repo}};			\
	else								\
		cd "$$extractdir";					\
		${_HG_CMD} pull ${_HG_FLAGS};				\
		${_HG_CMD} update -C ${_HG_FLAGS};			\
	fi
.endfor

# Debug info for show-all and show-all-hg
_VARGROUPS+=	hg
_USER_VARS.hg+=	CHECKOUT_DATE
_PKG_VARS.hg+=	HG_REPO HG_EXTRACTDIR HG_TAG HG_REPOSITORIES
_SYS_VARS.hg+=	DISTFILES PKGNAME PKGREVISION WRKSRC
_SYS_VARS.hg+=	_HG_PKGVERSION _HG_DISTDIR
.for repo in ${HG_REPOSITORIES}
.  for varbase in HG_REPO HG_EXTRACTDIR HG_TAG
_PKG_VARS.hg+=	${varbase}.${repo}
.  endfor
.  for varbase in _HG_TAG_FLAG _HG_TAG _HG_DISTFILE
_SYS_VARS.hg+=	${varbase}.${repo}
.  endfor
.endfor
_USE_VARS.hg+=	DISTNAME
