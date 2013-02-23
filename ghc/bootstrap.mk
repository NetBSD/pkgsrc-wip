# $NetBSD: bootstrap.mk,v 1.3 2013/02/23 12:24:07 phonohawk Exp $
# -----------------------------------------------------------------------------
# Select a bindist of bootstrapping compiler based on a per-platform
# basis.
#
# BOOT_ARCHIVE
#   This variable is set to the name of compressed archive file of a
#   bootstrapping compiler for the current platform.
#
# BOOT_TARBALL
#   Similar to BOOT_ARCHIVE, but "*.tar" not "*.tar.xz".
#
.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "i386" && ${OPSYS} == "FreeBSD"
BOOT_ARCHIVE=	${DISTNAME}-boot-i386-unknown-freebsd.tar.xz

.elif ${MACHINE_ARCH} == "i386" && ${OPSYS} == "NetBSD"
BOOT_ARCHIVE=	${DISTNAME}-boot-i386-unknown-netbsd.tar.xz

.elif ${MACHINE_ARCH} == "powerpc" && ${OPSYS} == "Darwin"
BOOT_ARCHIVE=	${DISTNAME}-boot-powerpc-apple-darwin.tar.xz
# Existence of libelf makes LeadingUnderscore being "NO", which is
# incorrect for this platform. See ${WRKSRC}/aclocal.m4
# (FP_LEADING_UNDERSCORE)
CONFLICTS+=	libelf-[0-9]*

.elif ${MACHINE_ARCH} == "x86_64" && ${OPSYS} == "Linux"
BOOT_ARCHIVE=	${DISTNAME}-boot-x86_64-unknown-linux.tar.xz

.elif ${MACHINE_ARCH} == "x86_64" && ${OPSYS} == "NetBSD"
BOOT_ARCHIVE=	${DISTNAME}-boot-x86_64-unknown-netbsd.tar.xz

.else
PKG_FAIL_REASON+=	"internal error: unsupported platform"
.endif

BOOT_TARBALL=	${BOOT_ARCHIVE:C/\.xz$//}


# -----------------------------------------------------------------------------
# The "pre-configure" hook
#
# Install a bootstrapping compiler directly into TOOLS_DIR so that
# ./configure can find it.
#
USE_TOOLS+=	gmake xzcat

pre-configure:
	@${PHASE_MSG} "Extracting bootstrapping compiler for ${PKGNAME}"
	${RUN} ${MKDIR} ${WRKDIR:Q}/build-extract
	${RUN} cd ${WRKDIR:Q}/build-extract && \
		${EXTRACT_CMD_DEFAULT} ${DISTDIR:Q}/${DIST_SUBDIR:Q}/${BOOT_ARCHIVE}

	@${PHASE_MSG} "Preparing bootstrapping compiler for ${PKGNAME}"
	${RUN} cd ${WRKDIR:Q}/build-extract/${DISTNAME}-boot && \
		${SH} ./configure \
			--prefix=${TOOLS_DIR:Q} \
			--with-gcc=${CCPATH:Q} && \
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
.PHONY: bootstrap

.if exists(${WRKDIR}/${DISTNAME}/mk/config.mk)
bootstrap:
	@${ERROR_MSG} "You have already configured the package in a way\
	that building bootstrapping compiler is impossible."
	@${FAIL_MSG}  "Please run \"${MAKE} clean patch\" first."

.elif !exists(${WRKDIR}/${DISTNAME}/rts/ghc.mk.orig)
bootstrap:
	@${FAIL_MSG} "Please run \"${MAKE} patch\" first."

.else
bootstrap: ${WRKDIR}/${BOOT_ARCHIVE}
	@${PHASE_MSG} "Done creating" ${WRKDIR}/${BOOT_ARCHIVE}

${WRKDIR}/lndir:
	@${PHASE_MSG} "Building lndir(1) to duplicate the source tree."
	cd ${WRKSRC:Q}/utils/lndir && \
		${CCPATH:Q} lndir.c -o ${.TARGET}

${WRKDIR}/stamp-lndir-boot: ${WRKDIR}/lndir
	@${PHASE_MSG} "Duplicating the source tree for bootstrapping ${DISTNAME}"
	${MKDIR} ${WRKDIR:Q}/build-boot
	cd ${WRKDIR:Q}/build-boot && \
		${WRKDIR}/lndir -silent ../${DISTNAME:Q}
	${TOUCH} ${.TARGET}

${WRKDIR}/stamp-configure-boot: ${WRKDIR}/stamp-lndir-boot
	@${PHASE_MSG} "Configuring bootstrapping compiler ${DISTNAME}"
	${MKDIR} ${WRKDIR:Q}/build-boot
	cd ${WRKDIR:Q}/build-boot && \
		${SH} ./configure --with-gcc=${CCPATH:Q} && \
		${LN} -f ${FILESDIR:Q}/bootstrap.build.mk mk/build.mk
	${TOUCH} ${.TARGET}

${WRKDIR}/stamp-build-boot: ${WRKDIR}/stamp-configure-boot
	@${PHASE_MSG} "Building bootstrapping compiler ${DISTNAME}"
	${RUN} cd ${WRKDIR:Q}/build-boot && ${BUILD_MAKE_CMD}
	${TOUCH} ${.TARGET}

${WRKDIR}/${BOOT_TARBALL}: ${WRKDIR}/stamp-build-boot
	@${PHASE_MSG} "Creating binary distribution of bootstrapping ${DISTNAME}"
	${RUN} cd ${WRKDIR:Q}/build-boot && ${BUILD_MAKE_CMD} binary-dist
	${MV} -f ${WRKDIR:Q}/build-boot/${BOOT_TARBALL} ${.TARGET}

# This can take up half an hour. Memory usage is also very high, about 680 MiB.
${WRKDIR}/${BOOT_ARCHIVE}: ${WRKDIR}/${BOOT_TARBALL}
	@${PHASE_MSG} "Compressing binary distribution of bootstrapping ${DISTNAME}"
	${PREFIX:Q}/bin/xz --verbose -9 --extreme ${WRKDIR:Q}/${BOOT_TARBALL}
.endif
