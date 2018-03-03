# $NetBSD$
#
# This file provides simple access to CVS repositories, so that packages
# can be created from CVS instead of from released tarballs. Whenever a
# package is fetched from CVS, an archive is created from it and saved
# below ${DISTDIR}, to save bandwidth.
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
# CVS_ROOT (required)
#	The CVSROOT of the CVS repository, including anoncvs password,
#	if applicable.
#
#	Examples:
#		${CVS_ROOT_GNU}/emacs
#		:pserver:anoncvs:@anoncvs.example.com:/cvsroot/project
#
# CVS_MODULE (optional)
#	The CVS module to check out. This typically corresponds to one
#	of the directories below CVS_ROOT.
#
#	Default: ${DISTNAME} without the version number
#
# CVS_EXTRACTDIR (optional)
#	The directory where the repository is checked out, relative to
#	${WRKDIR}.
#	Mostly useful when having multiple repositories.
#
#	Default: ${CVS_MODULE}
#
# CVS_TAG (optional)
#	The CVS tag that is checked out. If no tag is specified, the
#	latest daily version is checked out, influencing the PKGREVISION.
#
#	Default: (today at midnight)
#	Example: v1.0.0
#
# CVS_REPOSITORIES (optional)
#	If the package needs multiple CVS repositories, this
#	is the list of repository IDs. For each of these repositories,
#	parameterized variants of the above variables are defined.
#
#	The default value for CVS_EXTRACTDIR.${repo} is ${repo},
#	the repository ID.
#
#	Example:
#	CVS_REPOSITORIES=	stable latest
#	CVS_ROOT.stable=	${CVS_GNU_ROOT}/project
#	CVS_TAG.stable=		v1.2.3
#	CVS_ROOT.latest=	${CVS_GNU_ROOT}/project
#
# CVS_PROJECT
#	The project name to be used in CVS_ROOT_SOURCEFORGE.
#
#	Default: ${PKGBASE}
#
# Variables set by this file:
#
# CVS_ROOT_GNU
# CVS_ROOT_NONGNU
# CVS_ROOT_SOURCEFORGE
#	Common CVS repository locations for use in the CVS_ROOT
#	variables.
#
# DISTFILES
#	Defaults to an empty list.
#	This means that MASTER_SITES does not need to be defined.
#
# PKGNAME
#	Defaults to the package name from DISTNAME, combined
#	with the current date. This is useful when no CVS_TAG variables
#	are defined. When they are defined (and there may be multiple
#	ones), the package author should define PKGNAME explicitly.
#
# PKGREVISION
#	If the package doesn't set a specific CVS_TAG, this defaults
#	to today in the format yyyymmdd, e.g. 20180225.
#	This keeps the packages distinguishable since the HEAD might
#	change anytime.
#
# Keywords: cvs

# Defaults for package-settable variables
DISTFILES?=		# empty
PKGNAME?=		${DISTNAME:C,-[0-9].*,,}-cvs-${_CVS_PKGVERSION}
# Enforce PKGREVISION unless CVS_TAG is set:
.if empty(CVS_TAG)
.  if defined(CHECKOUT_DATE)
PKGREVISION?=		${CHECKOUT_DATE:S/-//g}
.  else
PKGREVISION?=		${_CVS_PKGVERSION:S/.//g}
.  endif
.endif

# The common case of a single repository
.if defined(CVS_ROOT)
CVS_MODULE?=		${PKGBASE:S,-cvs$,,}
CVS_EXTRACTDIR?=	${CVS_MODULE}
CVS_REPOSITORIES+=	default
WRKSRC?=		${WRKDIR}/${CVS_MODULE}
.  for varbase in CVS_ROOT CVS_MODULE CVS_TAG CVS_EXTRACTDIR
.    if defined(${varbase})
${varbase}.default=	${${varbase}}
.    endif
.  endfor
.endif

# Commonly used repositories
CVS_ROOT_GNU=		:pserver:anonymous:@cvs.savannah.gnu.org:/sources
CVS_ROOT_NONGNU=	${CVS_ROOT_GNU}
CVS_ROOT_SOURCEFORGE=	:pserver:anonymous:@${CVS_PROJECT}.cvs.sourceforge.net:/cvsroot/${CVS_PROJECT}
CVS_PROJECT?=		${PKGBASE}

CVS_REPOSITORIES?=	# none
.if empty(CVS_REPOSITORIES)
PKG_FAIL_REASON+=	"[cvs-package.mk] CVS_REPOSITORIES must be set."
.endif

.for repo in ${CVS_REPOSITORIES}
.  if empty(CVS_ROOT.${repo})
PKG_FAIL_REASON+=	"[cvs-package.mk] CVS_ROOT."${repo:Q}" must be set."
.  endif
.endfor

USE_TOOLS+=		date gzip pax

_CVS_RSH=		ssh
_CVS_CMD=		cvs
_CVS_ENV=		# empty
_CVS_ENV+=		CVS_PASSFILE=${_CVS_PASSFILE}
_CVS_ENV+=		CVS_RSH=${_CVS_RSH:Q}
_CVS_FLAGS=		-Q -z3
_CVS_CMDLINE=		${SETENV} ${_CVS_ENV} ${_CVS_CMD} ${_CVS_FLAGS}
_CVS_CHECKOUT_FLAGS=	-P
_CVS_PASSFILE=		${WRKDIR}/.cvs_passwords
_CVS_PKGVERSION?=	${${DATE} -u +'%Y.%m.%d':L:sh}
_CVS_DISTDIR=		${DISTDIR}/cvs-packages

.for repo in ${CVS_REPOSITORIES}
CVS_MODULE.${repo}?=		${repo}
CVS_EXTRACTDIR.${repo}?=	${repo}
.  if defined(CVS_TAG)
CVS_TAG.${repo}?=		${CVS_TAG}
.  endif

# Determine appropriate checkout date or tag
.  if defined(CVS_TAG.${repo})
_CVS_REV_ARGS.${repo}=	-r ${CVS_TAG.${repo}:Q}
_CVS_REV.${repo}=	${CVS_TAG.${repo}}
.  else
_CVS_DATE.${repo}=	${CHECKOUT_DATE:U${${DATE} -u +'%Y-%m-%d':L:sh}}
_CVS_REV_ARGS.${repo}=	-D ${_CVS_DATE.${repo}}\ 00:00:00\ +0000
_CVS_REV.${repo}=	${_CVS_DATE.${repo}}
.  endif

# The cached archive
_CVS_DISTFILE.${repo}=	${PKGBASE}-${repo}-${_CVS_REV.${repo}}.tar.gz

# Define the shell variables used by the following commands
_CVS_CMD.vars.${repo}= \
	root=${CVS_ROOT.${repo}:Q}; \
	module=${CVS_MODULE.${repo}:Q}; \
	extractdir=${CVS_EXTRACTDIR.${repo}:Q}; \
	archive=${_CVS_DISTDIR}/${_CVS_DISTFILE.${repo}:Q}

# Extract the cached archive
_CVS_CMD.extract_archive.${repo}= \
	if [ -f "$$archive" ]; then					\
	  ${STEP_MSG} "Extracting cached CVS archive $${archive\#\#*/}."; \
	  gzip -d -c "$$archive" | pax -r;				\
	  exit 0;							\
	fi

# Log in to a repository
.  if !empty(CVS_ROOT.${repo}:M\:pserver\:*)
_CVS_CMD.login.${repo}= \
	${TOUCH} ${_CVS_PASSFILE};					\
	${STEP_MSG} "Logging in to $$root.";				\
	${_CVS_CMDLINE} -d "$$root" login
.  else
_CVS_CMD.login.${repo}= \
	${DO_NADA}
.  endif

# Check out a repository
_CVS_CMD.checkout.${repo}= \
	${STEP_MSG} "Checking out $$module from $$root.";		\
	${_CVS_CMDLINE} -d "$$root"					\
	    checkout ${_CVS_CHECKOUT_FLAGS} ${_CVS_REV_ARGS.${repo}}	\
	      -d "$$extractdir" "$$module"

# Create the cached archive from the checked out repository
_CVS_CMD.create_archive.${repo}= \
	${STEP_MSG} "Creating cached CVS archive $${archive\#\#*/}.";	\
	${MKDIR} "$${archive%/*}";					\
	pax -w "$$extractdir" | gzip > "$$archive.tmp";			\
	${MV} "$$archive.tmp" "$$archive"
.endfor

pre-extract: do-cvs-extract

do-cvs-extract: .PHONY
.for repo in ${CVS_REPOSITORIES}
	${RUN} \
	cd ${WRKDIR}; \
	${_CVS_CMD.vars.${repo}}; \
	${_CVS_CMD.extract_archive.${repo}}; \
	${_CVS_CMD.login.${repo}}; \
	${_CVS_CMD.checkout.${repo}}; \
	${_CVS_CMD.create_archive.${repo}}
.endfor

# Debug info for show-all and show-all-cvs
_VARGROUPS+=		cvs
_USER_VARS.cvs+=	CHECKOUT_DATE
_PKG_VARS.cvs+=		CVS_ROOT CVS_MODULE CVS_TAG CHECKOUT_DATE CVS_EXTRACTDIR CVS_REPOSITORIES
_SYS_VARS.cvs+=		DISTFILES PKGNAME PKGREVISION WRKSRC
_SYS_VARS.cvs+=		CVS_ROOT_GNU CVS_ROOT_NONGNU CVS_ROOT_SOURCEFORGE CVS_PROJECT
_SYS_VARS.cvs+=		_CVS_DISTDIR _CVS_PKGVERSION
.for repo in ${CVS_REPOSITORIES}
.  for varbase in CVS_ROOT CVS_MODULE CVS_TAG CVS_EXTRACTDIR
_PKG_VARS.cvs+=		${varbase}.${repo}
.  endfor
.  for varbase in _CVS_DISTFILE
_SYS_VARS.cvs+=		${varbase}.${repo}
.  endfor
.  for varbase in _CVS_REV_ARGS _CVS_REV
_DEF_VARS.cvs+=		${varbase}.${repo}
.  endfor
.endfor
_USE_VARS.cvs+=		DISTNAME
