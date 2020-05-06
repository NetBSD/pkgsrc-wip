# $NetBSD$
#
# gitlab.com master site handling
#
# To use, set in Makefile:
#
# DISTNAME=	exampleproject-1.2
# MASTER_SITES=	${MASTER_SITE_GITLAB:=accountname/}
#
# The following variables alter gitlab.mk behavior:
#
# GITLAB_PROJECT	defaults to PKGBASE
# GITLAB_TAG		defaults to PKGVERSION_NOREV
#			sometimes you want to override with v${PKGVERSION_NOREV}
#			SHA-1 commit ids are also acceptable
# GITLAB_TYPE		overrides the autodetected MASTER_SITE URL scheme.
#			So far it defaults to tag, as Gitlab custom release files
#			are new and rare, and handled differently.
#
# "tag"
# This is the default when GITLAB_RELEASE is not defined. Example URL:
# https://gitlab.com/acct/${GITLAB_PROJECT}/-/archive/${GITHUB_TAG}/${GITLAB_PROJECT}-${GITLAB_TAG}.tar.gz
#
# "release"
# Real life example for a release:
# https://gitlab.com/teknokatze/fish-guix/uploads/40ed37a9c916b533ba69b37ec99f2939/fish-guix-0.1.2.3.tar.xz
# Corresponding tag and commit:
# https://gitlab.com/teknokatze/fish-guix/-/commit/23a3ec027bc5b14b41d96b14a2451c49e935e2b6
# https://gitlab.com/teknokatze/fish-guix/-/tags/0.1.2.3
# https://gitlab.com/teknokatze/fish-guix/-/archive/0.1.2.3/fish-guix-0.1.2.3.tar.gz
#
# Keywords: gitlab

MASTER_SITE_GITLAB+=	https://gitlab.com/

.if defined(MASTER_SITES) && !empty(MASTER_SITES:C,^https\://gitlab.com/[-a-zA-Z0-9]*/$,match,:Mmatch)
_USE_GITLAB=		YES
.endif

.if (defined(GITLAB_TAG) || defined(GITLAB_RELEASE)) && !defined(_USE_GITLAB)
PKG_FAIL_REASON+=	"MASTER_SITES must match https://gitlab.com/account/"	\
			"when GITLAB_TAG or GITLAB_RELEASE is in use."		\
			"For more information: make help topic=gitlab"
.endif

.if defined(_USE_GITLAB) && !empty(_USE_GITLAB:M[yY][eE][sS])

GITLAB_PROJECT?=	${PKGBASE}
GITLAB_TAG?=		${PKGVERSION_NOREV}

.  if !empty(GITLAB_TAG:Mmaster)
PKG_FAIL_REASON+=	"master is not a valid tag name, use an explicit commit hash"
.  endif

.  if !empty(GITLAB_TYPE:Mrelease) && empty(GITLAB_RELEASE_HASH)
PKG_FAIL_REASON+=	"GITLAB_RELEASE requires GITLAB_RELEASE_HASH to be used"
.  endif

.  if !defined(GITLAB_TYPE)
.    if defined(GITLAB_RELEASE) && !empty(GITLAB_RELEASE)
GITLAB_TYPE=	release
.    else
GITLAB_TYPE=	tag
.    endif
.  endif

.  if !empty(GITLAB_TYPE:Mtag) && !empty(GITLAB_TAG:M[a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9]*)
# If the gitlab tag is a git hash (7 or more hex digits), encode it in the
# distfile name.
_GITLAB_DEFAULT_DISTFILES=	${DISTNAME}-${GITLAB_TAG}${EXTRACT_SUFX}
.  else
_GITLAB_DEFAULT_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.  endif

.  if !empty(GITLAB_TYPE:Mrelease) && !empty(GITLAB_RELEASE_HASH)
SITES.${_GITLAB_DEFAULT_DISTFILES}=	-${MASTER_SITES:=${GITLAB_PROJECT}/uploads/${GITLAB_RELEASE_HASH}/${GITLAB_RELEASE}${EXTRACT_SUFX}}
.  endif

.  if !empty(GITLAB_TYPE:Mtag)
SITES.${_GITLAB_DEFAULT_DISTFILES}=	-${MASTER_SITES:=${GITLAB_PROJECT}/-/archive/${GITLAB_TAG}/${GITLAB_PROJECT}-${GITLAB_TAG}${EXTRACT_SUFX}}
.  endif

.endif

_VARGROUPS+=		gitlab
_PKG_VARS.gitlab=	GITLAB_PROJECT DISTNAME GITLAB_TYPE GITLAB_TAG \
			GITLAB_RELEASE GITLAB_RELEASE_HASH MASTER_SITES EXTRACT_SUFX
_DEF_VARS.gitlab=	_USE_GITLAB _GITLAB_DEFAULT_DISTFILES \
			SITES.${_GITLAB_DEFAULT_DISTFILES}
_USE_VARS.gitlab=	PKGBASE PKGVERSION_NOREV
_LISTED_VARS.gitlab=	SITES.*
