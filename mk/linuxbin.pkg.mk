# $NetBSD: linuxbin.pkg.mk,v 1.27 2011/01/14 21:32:26 asau Exp $

BROKEN=		Please update linuxbin.pkg.mk for the new emulator framework.

###########################################################################
#
# $Id: linuxbin.pkg.mk,v 1.27 2011/01/14 21:32:26 asau Exp $
#
# Proposal: how should we deal with Linux binary packages packages
#
# Currently supports:
#   * rpm
#   * "plain" -> .tgz, .tbz2,
#   * slackware packages (.tgz, but need slackware_compat)
#
# TODO:
#   * deb
#
# I have included comments, indents and unneeded spacings, so you can
# read this file more easily.
#
# (C) 2003, 2004 Michal Pasternak <dotz@irc.pl>
#

.if !defined(LINUXBIN_MK)
LINUXBIN_MK=		# defined

# look below for explanation on this:
.if defined(LINUX_DOWNLOAD)
INTERACTIVE_STAGE+=	fetch
.endif

.include "../../mk/bsd.prefs.mk"

###########################################################################
#
# First, we check if Linux binaries are supported on this platrofm
#
# defaults to your machine architecture.
#

LINUX_ARCH_REQD?=	${MACHINE_ARCH}

# by default, we can run Linux binaries only on the same OS (Linux), on the
# same machine arch:

ONLY_FOR_PLATFORM=	Linux-*-${MACHINE_ARCH}

# ... but, in case we're running on i386:

.if ${LINUX_ARCH_REQD}=="i386"
# on i386, {Free,Net,Open}BSD and probably DragonFlyBSD
# please add other OS, that have Linux emul and work on i386
#
ONLY_FOR_PLATFORM+=	[DFNO]*BSD-*-${LINUX_ARCH_REQD}
.endif

# PLEASE ADD MORE .if ${LINUX_ARCH_REQD} ifdefs !

###########################################################################
#
# Aloha, this is IMPORTANT:
#
# which linux base (suse/debian?/rh?) do we want:
#
#

#
# LINUX_BASE_PREFERRED should be set in mk/defaults or /etc/mk.conf
# This setting show us the user / sysadmin preference for a given linux base
#

LINUX_BASE_PREFERRED?=		suse

#
# LINUX_BASE_REQUIRED is *per package* setting (SuSE-only apps set this to
# suse, Slackware apps - to slackware and so on)
#
#
# TODO: make it possible, that we somehow can override LINUX_BASE_VERSION
# and make a given package require at least x.x.x version of linux_base
#

LINUX_BASE_REQUIRED?=		${LINUX_BASE_PREFERRED}

LINUX_BASE_PREFIX.suse?=	suse100
LINUX_BASE_VERSION.suse=	9.1

LINUX_BASE_PREFIX.slackware?=	slackware
LINUX_BASE_VERSION.slackware?=	9.1.0

#
# those will be not needed when slackware-base is in /emulators, for example
#

LINUX_PKGSRCDIR.suse=		emulators
LINUX_PKGSRCDIR.slackware=     	wip

# ... and finally:
LINUX_BASE_PREFIX=		${LINUX_BASE_PREFIX.${LINUX_BASE_REQUIRED}}

# TODO: add here in the future more linux bases:
# LINUX_BASE_PREFIX.debian?=

# define it to automatically depend on X11:
LINUX_USE_X11?=			NO

###########################################################################
#
# format of Linux binary packages. only rpm, slack and tgz are supported,
# but in future we could try adding more
#

LINUX_BINPKG_FMT?=		rpm

# in the future:
# LINUX_BINPKG_FMT?=		deb

# for packages, that only copy binary files and don't need rpm/deb pre-parsing
# LINUX_BINPKG_FMT?=		plain

# insert paths to binary Linux files you want to install
LINUX_BINPKG_PATH?=	${WRKSRC}
LINUX_BINPKG_FILES?=    # empty

###########################################################################
#
# enough settings, we'll start working here:

#
# first, include base linux files, that this port depends on.
# of course, pkgsrc working on Linux won't need compat files:
#

.if ( ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFlyBSD")

#
# LINUX_BASE_NODEPS is useful only for Linux binary packages, which are
# base package itself, or come so statically compiled, that don't need
# linux_base packages (rar3 for Linux?)
#

.if !defined(LINUX_BASE_NODEPS)
DEPENDS+=${LINUX_BASE_PREFIX}_compat>=${LINUX_BASE_VERSION.${LINUX_BASE_REQUIRED}}:../../${LINUX_PKGSRCDIR.${LINUX_BASE_REQUIRED}}/${LINUX_BASE_PREFIX}_compat
.endif

.if !empty(LINUX_USE_X11:M[Yy][Ee][Ss])
DEPENDS+=${LINUX_BASE_PREFIX}_x11>=${LINUX_BASE_VERSION.${LINUX_BASE_REQUIRED}}:../../${LINUX_PKGSRCDIR.${LINUX_BASE_REQUIRED}}/${LINUX_BASE_PREFIX}_x11
.endif

# do not check shlibs by default, since the wrong ldd will be run
CHECK_SHLIBS?=	no
.endif

###########################################################################
#
# definitely don't build binary packages:

NO_BUILD?=		YES

###########################################################################
#
# To EMULSUBDIR or not to EMULSUBDIR... this is a question.
#
# In future, the user should be able to:
#
# - have different Linux bases on his/hers machine - via changing variable,
#   say, LINUX_BASE_PREFERRED in /etc/mk.conf
#
# - some RPMs will work with work with Suse, some other with Redhat. Debs
#   will work with Debian.
#
# - we will need different EMULSUBDIR in the future
#
# - for now, i'm leaving this as default, but this _should_ be changed to,
#   say, ${EMULSUBDIR}_${LINUX_BASE_REQUIRED}
#
# - Linux pkgsrc users could set this as "/" if LINUX_BASE_REQD equals their
#   distribution

EMULSUBDIR?=		emul/linux
EMULOPTSUBDIR?=		${EMULSUBDIR}/opt
EMULDIR?=		${PREFIX}/${EMULSUBDIR}
EMULOPTDIR?=		${PREFIX}/${EMULOPTSUBDIR}

###########################################################################
#
# little messy, but it makes porting packages easier:

PLIST_SUBST+=		EMULDIR=${EMULDIR:Q} EMULSUBDIR=${EMULSUBDIR:Q} \
			EMULOPTDIR=${EMULOPTDIR:Q} EMULOPTSUBDIR=${EMULOPTSUBDIR:Q}
MESSAGE_SUBST+=		EMULDIR=${EMULDIR:Q} EMULSUBDIR=${EMULSUBDIR:Q} \
			EMULOPTDIR=${EMULOPTDIR:Q} EMULOPTSUBDIR=${EMULOPTSUBDIR:Q}

###########################################################################
#
# now, do the _actual_ work:
#
# TODO: pkglint is somehow picky about this, anyone could correct it?
#
# TODO: add automatic ldconfig for "plain" packages
#

.if ${LINUX_BINPKG_FMT}=="rpm"
#
# those below are ripoffs of suse_linux/Makefile.common
#

PLIST_SRC?=		${WRKDIR}/PLIST_DYNAMIC
RPM2PKG?=		${PREFIX}/sbin/rpm2pkg
BUILD_DEPENDS+=		rpm2pkg>=1.3:../../pkgtools/rpm2pkg
RPM2PKGARGS=		-d ${PREFIX} -f ${PLIST_SRC} -p ${EMULSUBDIR}
.for temp in ${RPMIGNOREPATH}
RPM2PKGARGS+=		-i ${temp:Q}
.endfor
.for temp in ${LINUX_BINPKG_FILES}
RPM2PKGARGS+=		${LINUX_BINPKG_PATH:Q}/${temp:Q}
.endfor
.if !target(do-install)
do-install:
	${_PKG_SILENT}${_PKG_DEBUG} set -e; \
	if [ -f ${PKGDIR}/PLIST ]; then \
	  ${CP} ${PKGDIR}/PLIST ${PLIST_SRC}; \
	else \
	  ${RM} -f ${PLIST_SRC}; \
	  ${CP} ${PKGSRCDIR}/emulators/suse_linux/PLIST_dynamic ${PLIST_SRC} ; \
	fi
	${RPM2PKG} ${RPM2PKGARGS}
	${_PKG_SILENT}${_PKG_DEBUG} set -e; \
	if ${GREP} -q 'lib.*\.so' ${PLIST_SRC}; then \
	  ${ECHO_MSG} "===> [Automatic Linux shared object handling]"; \
	  ${EMULDIR}/sbin/ldconfig -r ${EMULDIR} || ${TRUE}; \
	  ${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" >> ${PLIST_SRC}; \
	  ${ECHO} "@unexec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR} 2>/dev/null" >> ${PLIST_SRC}; \
	fi
.endif
.elif ${LINUX_BINPKG_FMT}=="plain"
.if !target(do-install)
do-install:
	@${ECHO} "Please provide do-install target for plain binaries!"
	@exit -1
.endif

.elif ${LINUX_BINPKG_FMT}=="slackware"
#
# installation procedures for slackware packages
# they basically come with install/doinst.sh script,
#
# so what we want to do is move all files to ${EMULSUBDIR},
# chroot to ${EMULSUBDIR} and launch doinst.sh
#
# only slackware_base packages for slackware won't use this method (eg. we can't
# chroot without shell and shared libs - so for them there is SLACK_NO_INSTALL
# setting)
#
# TODO: there's no chroot def in pkgsrc/mk
#

.if !target(do-install)
#
# WARNING: this is a bit lame - warn-on-freebsd target is in
# slackware_compat/Makefile.common, while this file (linuxbin.pkg.mk) never
# includes this directly (but slackware_* apps do include this file via
# slackware_compat/Makefile.common)
#
# This should be rewritten properly before it gets imported to pkgsrc
#
do-install: warn-on-freebsd
	cd ${WRKSRC} && ${PAX} -rw -pe * ${EMULDIR}
.if !defined(SLACK_NO_INSTALL)
	if [ -f ${EMULDIR}/install/doinst.sh ]; then \
		chroot ${EMULDIR} bin/bash install/doinst.sh; \
	fi
	${RM} -rf ${EMULDIR}/install
.endif
.endif

.else
PKG_FAIL_REASON+=	"[linuxbin.pkg.mk] Please add support for this kind of package!"
.endif

###########################################################################
#
# many Linux commercial packages require some voodoo before actual
# downloading, so why not put it here... define LINUX_DOWNLOAD
# in your Makefile and you're off with that step.
#

.if defined(LINUX_DOWNLOAD)
FETCH_MESSAGE?=
	"======================================================================" \
	"" \
	"The files for this package need to be downloaded from" \
	"" \
	"        ${LINUX_DOWNLOAD}" \
	"" \
	"into:"; \
	"" \
	"        ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}" \
	"" \
	"======================================================================"
.endif

.endif
