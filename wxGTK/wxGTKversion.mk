# $NetBSD$
#
# This file selects a wxGTK version, based on the user's preferences and
# the installed packages. It does not add a dependency on the wxGTK
# package. You may place following line after this file included:
# 	.include "${WXGTKPKGSRCDIR}/buildlink3.mk"
#
# === User-settable variables ===
#
# WXGTK_VERSION_DEFAULT
#	The wxGTK version to choose when more than one is acceptable to
#	the package.
#
#	Possible: 28 30
#	Default: 28
#
# === Infrastructure variables ===
#
# WXGTK_VERSION_REQD
#	wxGTK version to use. This variable should not be set in
#	packages.  Normally it is used by bulk build tools.
#
#	Possible: ${WXGTK_VERSIONS_ACCEPTED}
#	Default:  ${WXGTK_VERSION_DEFAULT}
#
# === Package-settable variables ===
#
# WXGTK_VERSIONS_ACCEPTED
#	The wxGTK versions that are accepted by the package.
#
#	Possible: 28 30
#	Default: 28
#
# WXGTK_CHECK_INSTALLED
#	Check installed version of wxGTK.  Should be used by x11/wxGTK28
#	and x11/wxGTK30 (etc) only.
#
#	Possible: Yes No
#	Default: Yes
#
# === Variables defined by this file ===
#
# PKG_WXGTK_VERSION
#	The selected wxGTK version.
#
#	Possible: 28 30
#	Default: ${WXGTK_VERSION_DEFAULT}
#
# WXGTK_BASE_VERS
#	The selected wxGTK's full version depends on PKG_WXGTK_VERSION
#
##  PKG_WXGTK_MAJOR_VERS
## 	The selected wxGTK's major version.
## 
## 	Possible: 5
## 	Default: 5
#
# PKG_WXGTK
#	The same as ${PKG_WXGTK_VERSION}, prefixed with "wxGTK-".
#
# WXGTKPKGSRCDIR
#	The directory of the wxGTK implementation, relative to the
#	package directory.
#
#	Example: ../../x11/wxGTK28
#
# WXGTK_PKG_PREFIX
#	The prefix that is prepended to the package name.
#
#	Example: wxGTK28-, wxGTK30-
#
##  WXGTK_EXTENSION_DIR
## 	Relative path to ${PREFIX} for wxGTK's extensions.  It is derived from
## 	initial release of major version.
## 
## 	Example: lib/php/20090630
#
# Keywords: wxGTK
#

.if !defined(WXGTKVERSION_MK)
WXGTKVERSION_MK=	defined

# Define each wxGTK's version.
WXGTK24_VERSION=	2.4.2
WXGTK26_VERSION=	2.6.3
WXGTK28_VERSION=	2.8.12
WXGTK30_VERSION=	3.0.2

# # Define initial release of major version.
# WXGTK54_RELDATE=	20120301
# WXGTK55_RELDATE=	20130620
# WXGTK56_RELDATE=	20140828

_VARGROUPS+=	wxGTK
_USER_VARS.wxGTK=	WXGTK_VERSION_DEFAULT
_PKG_VARS.wxGTK=	WXGTK_VERSIONS_ACCEPTED WXGTK_VERSION_REQD
_SYS_VARS.wxGTK=	PKG_WXGTK_VERSION PKG_WXGTK WXGTKPKGSRCDIR WXGTK_PKG_PREFIX \
		PKG_WXGTK_MAJOR_VERS

.include "../../mk/bsd.prefs.mk"

WXGTK_VERSION_DEFAULT?=		28
WXGTK_VERSIONS_ACCEPTED?=	28 30

# transform the list into individual variables
.for wv in ${WXGTK_VERSIONS_ACCEPTED}
_WXGTK_VERSION_${wv}_OK=	yes
.endfor

# check what is installed
.if exists(${LOCALBASE}/include/wx-2.8)
_WXGTK_VERSION_28_INSTALLED=	yes
_WXGTK_INSTALLED=		yes
.elif exists(${LOCALBASE}/include/wx-3.0)
_WXGTK_VERSION_30_INSTALLED=	yes
_WXGTK_INSTALLED=		yes
.endif

# if a version is explicitely required, take it
.if defined(WXGTK_VERSION_REQD)
_WXGTK_VERSION=	${WXGTK_VERSION_REQD}
.endif
# if the default is already installed, it is first choice
.if !defined(_WXGTK_VERSION)
.if defined(_WXGTK_VERSION_${WXGTK_VERSION_DEFAULT}_OK)
.if defined(_WXGTK_VERSION_${WXGTK_VERSION_DEFAULT}_INSTALLED)
_WXGTK_VERSION=	${WXGTK_VERSION_DEFAULT}
.endif
.endif
.endif
# prefer an already installed version, in order of "accepted"
.if !defined(_WXGTK_VERSION)
.for wv in ${WXGTK_VERSIONS_ACCEPTED}
.if defined(_WXGTK_VERSION_${wv}_INSTALLED)
_WXGTK_VERSION?=	${wv}
.else
# keep information as last resort - see below
_WXGTK_VERSION_FIRSTACCEPTED?=	${wv}
.endif
.endfor
.endif
# if the default is OK for the addon pkg, take this
.if !defined(_WXGTK_VERSION)
.if defined(_WXGTK_VERSION_${WXGTK_VERSION_DEFAULT}_OK)
_WXGTK_VERSION=	${WXGTK_VERSION_DEFAULT}
.endif
.endif
# take the first one accepted by the package
.if !defined(_WXGTK_VERSION)
_WXGTK_VERSION=	${_WXGTK_VERSION_FIRSTACCEPTED}
.endif

#
# Variable assignment for multi-wxGTK packages
MULTI+=	WXGTK_VERSION_REQD=${_WXGTK_VERSION}

# export some of internal variables
PKG_WXGTK_VERSION:=	${_WXGTK_VERSION:C/\.[0-9]//}
PKG_WXGTK:=		WXGTK${_WXGTK_VERSION:C/([0-9])([0-9])/\1.\2/}

# currently we have only wxGTK 5.x packages.
#PKG_WXGTK_MAJOR_VERS:=	5

WXGTK_CHECK_INSTALLED?=	Yes

# if installed wxGTK isn't compatible with required wxGTK, bail out
.if empty(WXGTK_CHECK_INSTALLED:M[nN][oO])
.if defined(_WXGTK_INSTALLED) && !defined(_WXGTK_VERSION_${_WXGTK_VERSION}_INSTALLED)
PKG_FAIL_REASON+=	"Package accepts ${PKG_WXGTK}, but different version is installed"
.endif
.endif

MESSAGE_SUBST+=		PKG_WXGTK_VERSION=${PKG_WXGTK_VERSION} \
			PKG_WXGTK=${PKG_WXGTK}
PLIST_SUBST+=		PKG_WXGTK_VERSION=${PKG_WXGTK_VERSION} \
			PKG_WXGTK_MAJOR_VERS=${PKG_WXGTK_MAJOR_VERS} \
			WXGTK_EXTENSION_DIR=${WXGTK_EXTENSION_DIR}

# force the selected wxGTK version for recursive builds
WXGTK_VERSION_REQD:=	${PKG_WXGTK_VERSION}

#
# set variables for the version we decided to use:
#
.if ${_WXGTK_VERSION} == "28"
WXGTKPKGSRCDIR=		../../x11/wxGTK28
WXGTK_VERSION=		${WXGTK28_VERSION}
WXGTK_INITIAL_TEENY=	12
WXGTK_PKG_PREFIX=	wxGTK28
.elif ${_WXGTK_VERSION} == "30"
WXGTKPKGSRCDIR=		../../x11/wxGTK30
WXGTK_VERSION=		${WXGTK30_VERSION}
WXGTK_INITIAL_TEENY=	2
WXGTK_PKG_PREFIX=	wxGTK30
.else
# force an error
PKG_FAIL_REASON+=	"${PKG_WXGTK} is not a valid package"
.endif

_WXGTK_VER_MAJOR=	${WXGTK_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
_WXGTK_VER_MINOR=	${WXGTK_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}

WXGTK_BASE_VERS=	${_WXGTK_VER_MAJOR}.${_WXGTK_VER_MINOR}.${WXGTK_INITIAL_TEENY}

#
# check installed version aginst required:
#
.if !empty(WXGTK_CHECK_INSTALLED:M[nN][oO])
.if defined(_WXGTK_VERSION_INSTALLED) && ${_WXGTK_VERSION} != ${_WXGTK_VERSION_INSTALLED}
PKG_FAIL_REASON+=	"${PKGBASE} requires ${PKG_WXGTK}, but wxGTK-${_WXGTK_VERSION_INSTALLED} is already installed."
.endif
.endif

.endif	# WXGTKVERSION_MK
