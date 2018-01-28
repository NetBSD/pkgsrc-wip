# $NetBSD$
# -----------------------------------------------------------------------------
# Select a bindist of bootstrapping compiler on a per-platform basis.
#
# BOOT_ARCHIVE
#   This variable is set to the name of compressed archive file of a
#   bootstrapping compiler for the current platform.
#
# BOOT_VERSION
#   Version of the bootstrapping compiler to use. This can be
#   overriden for specific platforms.
#
.include "../../mk/bsd.prefs.mk"

# Use the same version as the package itself by default.
BOOT_VERSION:=	${PKGNAME:C/^.*-//}

.if !empty(MACHINE_PLATFORM:MDarwin-*-x86_64) || make(distinfo)
BOOT_ARCHIVE:=		ghc-${BOOT_VERSION}-boot-x86_64-apple-darwin.tar.xz
DISTFILES:=		${DISTFILES} ${BOOT_ARCHIVE}
SITES.${BOOT_ARCHIVE}=	https://us-east.manta.joyent.com/pkgsrc/public/distfiles-local/
.endif

.if !empty(MACHINE_PLATFORM:MSunOS-5.11-i386) || make(distinfo)
BOOT_ARCHIVE:=		ghc-${BOOT_VERSION}-boot-i386-unknown-solaris2.tar.xz
DISTFILES:=		${DISTFILES} ${BOOT_ARCHIVE}
SITES.${BOOT_ARCHIVE}=	https://us-east.manta.joyent.com/pkgsrc/public/distfiles-local/
.endif

.if !empty(MACHINE_PLATFORM:MSunOS-5.11-x86_64) || make(distinfo)
BOOT_ARCHIVE:=		ghc-${BOOT_VERSION}-boot-x86_64-unknown-solaris2.tar.xz
DISTFILES:=		${DISTFILES} ${BOOT_ARCHIVE}
SITES.${BOOT_ARCHIVE}=	https://us-east.manta.joyent.com/pkgsrc/public/distfiles-local/
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo)
BOOT_ARCHIVE:=		ghc-${BOOT_VERSION}-boot-x86_64-unknown-netbsd.tar.xz
DISTFILES:=		${DISTFILES} ${BOOT_ARCHIVE}
SITES.${BOOT_ARCHIVE}=	ftp://ftp.netbsd.org/pub/NetBSD/misc/kamil/
.endif

.if empty(BOOT_ARCHIVE)
BOOT_ARCHIVE:=		ghc-${BOOT_VERSION}-boot-unknown.tar.xz
PKG_FAIL_REASON+=	"Unsupported platform, please generate bootstrap kit"
.endif

# For package developers, please do not upload any bootkits unsafely
# built. That is, machines shared with someone or on a cloud hosting
# service should be avoided for building bootkits.
.for i in ${DISTFILES:M*-boot-*}
SITES.${i}?=	${MASTER_SITE_LOCAL}
.endfor

# Existence of libelf makes LeadingUnderscore being "NO", which is
# incorrect for this platform. See ${WRKSRC}/aclocal.m4
# (FP_LEADING_UNDERSCORE)
.if ${OPSYS} == "Darwin"
CONFLICTS+=	libelf-[0-9]*
.endif

# FreeBSD < 10 surprisingly doesn't have a native iconv so we need to
# use pkgsrc libiconv for this OPSYS. And if a bootkit depends on
# pkgsrc libiconv, the "normal" build must do the same because GHC
# always needs to link executables with libiconv, just like libgmp
# when integer-gmp is used. For this reason it might be desirable to
# create two separate bootkits, one for < 10 and another for >= 10.
.if ${OPSYS} == "FreeBSD"
USE_BUILTIN.iconv=	no
.endif

# -----------------------------------------------------------------------------
# The "pre-configure" hook
#
# Install a bootstrapping compiler directly into TOOLS_DIR so that
# ./configure can find it.
#
USE_TOOLS+=	gmake xzcat xz

pre-configure:
	@${TEST} -f ${DISTDIR}/${DIST_SUBDIR}/${BOOT_ARCHIVE} || \
	${FAIL_MSG}  "Put your trusted bootstrap archive as ${DISTDIR}/${DIST_SUBDIR}/${BOOT_ARCHIVE}"

	@${PHASE_MSG} "Extracting bootstrapping compiler for ${PKGNAME}"
	${RUN} ${MKDIR} ${WRKDIR}/build-extract
	${RUN} cd ${WRKDIR}/build-extract && \
		${EXTRACT_CMD_DEFAULT} ${DISTDIR}/${DIST_SUBDIR}/${BOOT_ARCHIVE}

# It is important to install the stage-0 compiler with our rpath flags
# configured, otherwise it will produce executables with no rpath and
# fail in the configure phase.
	@${PHASE_MSG} "Preparing bootstrapping compiler for ${PKGNAME}"
	${RUN} cd ${WRKDIR}/build-extract/${PKGNAME_NOREV}-boot && \
		${PKGSRC_SETENV} ${CONFIGURE_ENV} ${SH} ./configure \
			--prefix=${TOOLS_DIR:Q} && \
		${MAKE_PROGRAM} install


# -----------------------------------------------------------------------------
# An unusual target "bootstrap"
#
# Build a bootstrapping compiler using an already installed GHC. This
# can certainly impossible if you don't have one. It's absolutely
# important to build it with the fewest possible run-time
# dependencies, otherwise the resulting binary can easily get
# unusable.
#

# We don't want our bootkits to have a run-time dependency on
# libgcc. In fact GHC's implementation of Haskell exception handling
# does not depend on libgcc's facilities so it is attractive to do the
# same for "normal" build... but we can't. This is because Haskell
# programs may call C functions via FFI, and those C functions may
# call C++ functions in turn, possibly in a different shared library.
.include "../../mk/compiler.mk"
.if make(bootstrap) && !empty(CC_VERSION:Mgcc-*)
# But on some platforms, gcc automagically inserts a dependency on a
# shared libgcc when -lpthread is given, which is seemingly
# unavoidable.
LDFLAGS+=	-static-libgcc
.endif

# Gather information about packages on which bootkit depends. It will
# be used in the post-bootstrap phase.
BOOT_GHC_DEPS:=		curses iconv
BOOT_GHC_PKGSRC_DEPS:=	# empty
.for pkg in ${BOOT_GHC_DEPS}

# NOTE: pkglint(1) complains for including these builtin.mk files,
# telling that we must include buildlink3.mk instead. But then how do
# we get variables like USE_BUILTIN.${pkg} defined before including
# ../../mk/bsd.pkg.mk, given that ../../mk/bsd.buildlink3.mk isn't
# protected against multiple inclusion?
CHECK_BUILTIN.${pkg}:=	yes
.  if ${pkg} == "curses"
.    include "../../mk/curses.builtin.mk"
.  elif ${pkg} == "iconv"
.    include "../../converters/libiconv/builtin.mk"
.  endif
CHECK_BUILTIN.${pkg}:=	no

# BOOT_GHC_PKGSRC_DEPS is a list of packages whose pkgsrc version is
# preferred over native one, either by user or ../../mk/platform
.  if ${PREFER.${pkg}} == "pkgsrc"
BOOT_GHC_PKGSRC_DEPS+=	${pkg}
.  endif
.endfor

# Compiler wrappers must not remove -I/-L flags for the installed
# GHC's libdir, otherwise the GHC we are going to use for building our
# bootstraping kit will not work at all. Ideally it should be added to
# BUILDLINK_PASSTHRU_DIRS only .if make(bootstrap), but then running
# "${MAKE} wrapper" before "${MAKE} bootstrap" will result in a
# cryptic error which we can't easily catch.
BOOT_GHC_LIBDIR_CMD=		ghc --print-libdir
.if !defined(BOOT_GHC_LIBDIR)
BOOT_GHC_LIBDIR!=		(${BOOT_GHC_LIBDIR_CMD}) 2>/dev/null || ${ECHO}
.endif
MAKEVARS+=			BOOT_GHC_LIBDIR
BUILDLINK_PASSTHRU_DIRS+=	${BOOT_GHC_LIBDIR}

# Default values for BUILDLINK_INCDIRS.<pkg> are only generated in the
# barrier. See ../../mk/buildlink3/bsd.buildlink3.mk and
# ../../mk/bsd.pkg.barrier.mk
.PHONY: bootstrap
.if make(bootstrap)
_BARRIER_CMDLINE_TARGETS+=	bootstrap
.endif
.if !defined(_PKGSRC_BARRIER)
bootstrap: barrier
.else
bootstrap: pre-bootstrap .WAIT ${WRKDIR}/${BOOT_ARCHIVE} .WAIT post-bootstrap
.endif

.PHONY: pre-bootstrap
pre-bootstrap: wrapper
.if empty(BOOT_GHC_LIBDIR)
	@if ${BOOT_GHC_LIBDIR_CMD} 2>/dev/null 1>&2; then \
		${ERROR_MSG} "Running \"${BOOT_GHC_LIBDIR_CMD}\" has failed during wrapper phase."; \
		${FAIL_MSG}  "Plase run \"${MAKE} clean\" and try again."; \
	else \
		${ERROR_MSG} "Failed to run \"${BOOT_GHC_LIBDIR_CMD}\":"; \
		${BOOT_GHC_LIBDIR_CMD}; \
		${ERROR_MSG} "You don't seem to have a working GHC in your PATH."; \
		${FAIL_MSG}  "Please install one and then run \"${MAKE} clean bootstrap\"."; \
	fi
.endif
# ${_COOKIE.configure} is not defined yet so we can't use .if here.
	@if ${TEST} -f ${_COOKIE.configure}; then \
		${ERROR_MSG} "You have already configured the package in a way\
		that building bootstrapping compiler is impossible."; \
		${FAIL_MSG}  "Please run \"${MAKE} clean\" first."; \
	fi

${WRKDIR}/lndir:
	@${PHASE_MSG} "Building lndir(1) to duplicate the source tree."
	cd ${WRKSRC}/utils/lndir && \
		${PKG_CC:Q} lndir.c -o ${.TARGET}

${WRKDIR}/stamp-lndir-boot: ${WRKDIR}/lndir
	@${PHASE_MSG} "Duplicating the source tree for bootstrapping ${PKGNAME_NOREV}"
	${MKDIR} ${WRKDIR}/build-boot
	cd ${WRKDIR}/build-boot && \
		${WRKDIR}/lndir -silent ../${PKGNAME_NOREV}
	${TOUCH} ${.TARGET}

# For terminfo_CONFIGURE_OPTS, see
# https://ghc.haskell.org/trac/ghc/ticket/10096
${WRKDIR}/stamp-configure-boot: ${WRKDIR}/stamp-lndir-boot
	@${PHASE_MSG} "Configuring bootstrapping compiler ${PKGNAME_NOREV}"
	${MKDIR} ${WRKDIR}/build-boot
	cd ${WRKDIR}/build-boot && \
		${PKGSRC_SETENV} ${CONFIGURE_ENV} ${SH} ./configure ${CONFIGURE_ARGS}
	${TOUCH} ${.TARGET}

${WRKDIR}/build-boot/mk/build.mk: ${WRKDIR}/stamp-configure-boot
	@${PHASE_MSG} "Configuring ${.TARGET}"
	${ECHO} "BuildFlavour = quick" >${.TARGET}
	${ECHO} "DYNAMIC_GHC_PROGRAMS = NO" >>${.TARGET}
	${CAT} ${WRKDIR}/build-boot/mk/build.mk.sample >>${.TARGET}
	${ECHO} "INTEGER_LIBRARY = integer-simple" >>${.TARGET}
	${ECHO} "BIN_DIST_NAME = ghc-\$$(ProjectVersion)-boot" >>${.TARGET}
	${ECHO} "libraries/terminfo_CONFIGURE_OPTS += \
	    --configure-option=--with-curses-includes=${BUILDLINK_PREFIX.curses}/${BUILDLINK_INCDIRS.curses} \
	    --configure-option=--with-curses-libraries=${BUILDLINK_PREFIX.curses}/${BUILDLINK_LIBDIRS.curses}" >>${.TARGET}

${WRKDIR}/stamp-build-boot: ${WRKDIR}/build-boot/mk/build.mk
	@${PHASE_MSG} "Building bootstrapping compiler ${PKGNAME_NOREV}"
	${RUN} cd ${WRKDIR}/build-boot && ${BUILD_MAKE_CMD}
	${TOUCH} ${.TARGET}

${WRKDIR}/${BOOT_ARCHIVE}: ${WRKDIR}/stamp-build-boot
	@${PHASE_MSG} "Creating binary distribution of bootstrapping ${PKGNAME_NOREV}"
	${RUN} cd ${WRKDIR}/build-boot && \
		${BUILD_MAKE_CMD} TAR_COMP=xz XZ_CMD="xz -9ev" binary-dist
	${MV} -f ${WRKDIR}/build-boot/${BOOT_ARCHIVE} ${.TARGET}

.PHONY: post-bootstrap
post-bootstrap:
	@${ECHO} "=========================================================================="
	@${ECHO} "Done creating ${BOOT_ARCHIVE}"
	@${ECHO} "  in ${WRKDIR}"
	@${ECHO}
	@${ECHO} "Now you can copy it into ${DISTDIR}/${DIST_SUBDIR} to use it as your"
	@${ECHO} "bootstrap kit. You may want to take a backup in case \"lintpkgsrc -r\""
	@${ECHO} "removes it."
	@${ECHO}
	@${ECHO} "Your bootstrap kit has the following run-time dependencies:"
.for pkg in ${BOOT_GHC_DEPS}
	@${PRINTF} "  * %-8s" "${pkg}:"
.  if !empty(USE_BUILTIN.${pkg}:M[nN][oO])
	@${ECHO_N} " pkgsrc ${BUILDLINK_PKGNAME.${pkg}}"
.  else
	@${ECHO_N} " native"
.    if empty(BUILTIN_PKG.${pkg})
	@${ECHO_N} " (version/variant unknown)"
.    else
	@${ECHO_N} " ${BUILTIN_PKG.${pkg}}"
.    endif
.  endif
	@${ECHO}
.endfor
.if !empty(BOOT_GHC_PKGSRC_DEPS)
	@${ECHO}
	@${ECHO} "Please note that it is generally not a good idea for a bootkit to depend"
	@${ECHO} "on pkgsrc packages, as pkgsrc tends to move faster than operating systems"
	@${ECHO} "so your bootkit may bitrot more quickly. You may want to rebuild it"
	@${ECHO} "without setting PREFER_PKGSRC to \"yes\"."
.endif
	@${ECHO} "=========================================================================="
