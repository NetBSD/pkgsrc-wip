# $NetBSD: linuxbin.pkg.mk,v 1.4 2003/11/28 22:02:45 mpasternak Exp $
# 
# $Id: linuxbin.pkg.mk,v 1.4 2003/11/28 22:02:45 mpasternak Exp $
#
# Proposal: how should we deal with Linux binary packages packages
# Currently supports only RPMs, but should be good enough to make
# support for .debs.
#
# I have included comments, indents and unneeded spacings, so you can
# read this file more easily.
#
#
# (C) 2003 Michal Pasternak <dotz@irc.pl>

.ifndef LINUXBIN_MK
LINUXBIN_MK=		# defined

.include "../../mk/bsd.prefs.mk"

# defaults to your machine architecture. 
LINUX_ARCH_REQD?=	${MACHINE_ARCH}

# by default, we can run Linux binaries only on the same OS (Linux), on the
# same machine arch:

ONLY_FOR_PLATFORM=	Linux-*-${MACHINE_ARCH}

# ... but, in case we're running on i386:

.if ${LINUX_ARCH_REQD}=="i386"
# on i386, NetBSD, FreeBSD and propably DragonFlyBSD
# please add other OS, that have Linux emul and work on i386
#
# I dont have no idea if OpenBSD has linux emul

ONLY_FOR_PLATFORM+=	[NFD]*BSD-*-${LINUX_ARCH_REQD}
.endif

# PLEASE ADD MORE .if ${LINUX_ARCH_REQD} ifdefs !



# which linux base (suse/debian?/rh?) do we want:
LINUX_BASE_REQUIRED?=		suse
LINUX_BASE_PREFIX.suse?=	suse

# ... and finally:
LINUX_BASE_PREFIX=		${LINUX_BASE_PREFIX.${LINUX_BASE_REQUIRED}}

# add here in the future more linux bases:
# LINUX_BASE_PREFIX.debian?=

# define it to automatically depend on X11:
LINUX_USE_X11?=			NO

# format of Linux binary packages. only RPM is supported, but in future we
# could try adding more
LINUX_BINPKG_FMT?=		rpm

# in the future:
# LINUX_BINPKG_FMT?=		deb

# for packages, that only copy binary files and don't need rpm/deb pre-parsing
# LINUX_BINPKG_FMT?=		plain

# insert paths to binary Linux files you want to install
LINUX_BINPKG_PATH?=	${WRKSRC}
LINUX_BINPKG_FILES?=    # empty

#
# enough settings, we'll start working here:
# first, include base linux files, that this port depends on.
# of course, pkgsrc working on Linux won't need compat files:
#

.if ( ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFlyBSD")
DEPENDS+=	${LINUX_BASE_PREFIX}_compat-[0-9]*:../../emulators/${LINUX_BASE_PREFIX}_compat
.if ${LINUX_USE_X11} == "yes" || ${LINUX_USE_X11} == "YES"
DEPENDS+=	${LINUX_BASE_PREFIX}_x11-[0-9]*:../../emulators/${LINUX_BASE_PREFIX}_x11
.endif
.endif

#
# those below are ripoffs of suse_linux/Makefile.common
#

NO_BUILD?=		YES

# To EMULSUBDIR or not to EMULSUBDIR... this is a question.
#
# In future, the user should be able to:
#
# - have different Linux bases on his/hers machine - via changing variable,
#   say, LINUX_BASE_PREFERED in /etc/mk.conf
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
EMULDIR?=		${PREFIX}/${EMULSUBDIR}

PLIST_SUBST+=		EMULDIR=${EMULDIR} EMULSUBDIR=${EMULSUBDIR}
MESSAGE_SUBST+=		EMULDIR=${EMULDIR} EMULSUBDIR=${EMULSUBDIR}

#
# now, do the _actual_ work:
#
# TODO: pkglint is somehow picky about this, anyone could correct it?
#
# TODO: add automatic ldconfig for "plain" type
#

.if ${LINUX_BINPKG_FMT}=="rpm"
PLIST_SRC?=		${WRKDIR}/PLIST_DYNAMIC
RPM2PKG?=		${PREFIX}/sbin/rpm2pkg
BUILD_DEPENDS+=		rpm2pkg>=1.3:../../pkgtools/rpm2pkg
RPM2PKGARGS=		-d ${PREFIX} -f ${PLIST_SRC} -p ${EMULSUBDIR}
.for TEMP in ${RPMIGNOREPATH}
RPM2PKGARGS+=		-i ${TEMP}
.endfor
.for TEMP in ${LINUX_BINPKG_FILES}
RPM2PKGARGS+=		${LINUX_BINPKG_PATH}/${TEMP}
.endfor

.if !target(do-install)
do-install:
	@if [ -f ${PKGDIR}/PLIST ]; then \
	  ${CP} ${PKGDIR}/PLIST ${PLIST_SRC}; \
	else \
	  ${RM} -f ${PLIST_SRC}; \
	  ${CP} ${_PKGSRCDIR}/emulators/suse_linux/PLIST_dynamic ${PLIST_SRC} ; \
	fi
	${RPM2PKG} ${RPM2PKGARGS}
	@if ${GREP} -q 'lib.*\.so' ${PLIST_SRC}; then \
	  ${ECHO_MSG} "===> [Automatic Linux shared object handling]"; \
	  ${EMULDIR}/sbin/ldconfig -r ${EMULDIR}; \
	  ${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" >> ${PLIST_SRC}; \
	  ${ECHO} "@unexec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR} 2>/dev/null" >> ${PLIST_SRC}; \
	fi
.endif
.else
.if ${LINUX_BINPKG_FMT}=="plain"
.if !target(do-install)
do-install:
	@echo "Please provide do-install target for plain binaries!"
	@exit -1       	
.endif
.else
.error "Please add support for this type of packages!"
.endif
.endif
.endif
