# $NetBSD: stage0.mk,v 1.3 2012/03/22 23:24:57 phonohawk Exp $

# Build an unregisterised bootstrap compiler and install it directly
# into the .buildlink directory. But we can't use "make install"
# because we don't build it in a standard way (./configure && make).
#
# To install it, we just copy ghc and ghc-pkg from
# "work/bootstrap/ghc-${VERSION}/inplace/bin" to
# "${BUILDLINK_DIR}/bin". Note that in-place ghc isn't usable until we
# run "ghc-pkg recache".

.if ${MACHINE_ARCH} == "i386" && ${OPSYS} == "NetBSD"
BOOTSTRAP_BUILD_MK = ${PKGDIR}/files/bootstrap-bsd.mk
BOOTSTRAP_CAPI_C   = ${PKGDIR}/files/capi-wrappers-netbsd-i386.c
BOOTSTRAP_TARBALL  = ${DISTNAME}-boot-i386-unknown-netbsdelf6.99.1.tar.bz2
PLATFORM           = i386-unknown-netbsd

.elif ${MACHINE_ARCH} == "i386" && ${OPSYS} == "FreeBSD"
BOOTSTRAP_BUILD_MK = ${PKGDIR}/files/bootstrap-bsd.mk
BOOTSTRAP_CAPI_C   = ${PKGDIR}/files/capi-wrappers-freebsd-i386.c
BOOTSTRAP_TARBALL  = ${DISTNAME}-boot-i386-unknown-freebsd8.0.tar.bz2
PLATFORM           = i386-unknown-freebsd

.elif ${MACHINE_ARCH} == "powerpc" && ${OPSYS} == "Darwin"
BOOTSTRAP_BUILD_MK = ${PKGDIR}/files/bootstrap.mk
BOOTSTRAP_CAPI_C   = ${PKGDIR}/files/capi-wrappers-darwin-powerpc.c
BOOTSTRAP_TARBALL  = ${DISTNAME}-boot-i386-unknown-darwin9.8.0.tar.bz2
PLATFORM           = powerpc-apple-darwin
# Existence of libelf makes LeadingUnderscore being "NO", which is
# incorrect for this platform. See ghc-6.12.1/aclocal.m4
# (FP_LEADING_UNDERSCORE)
CONFLICTS=	libelf-[0-9]*

.elif ${MACHINE_ARCH} == "x86_64" && ${OPSYS} == "Linux"
BOOTSTRAP_BUILD_MK = ${PKGDIR}/files/bootstrap-linux.mk
BOOTSTRAP_CAPI_C   = ${PKGDIR}/files/capi-wrappers-linux-x86_64.c
BOOTSTRAP_TARBALL  = ${DISTNAME}-boot-x86_64-unknown-linux-gnu.tar.bz2
PLATFORM           = x86_64-unknown-linux

.else
PKG_FAIL_REASON+=	"internal error: unsupported platform"
.endif

BOOTSTRAP_MAIN_C=	${PKGDIR}/files/bootstrap-main.c

pre-configure: ${WRKDIR}/stamp-bootstrap-ghc

${WRKDIR}/stamp-autoreconf:
	${RUN} cd ${WRKSRC} && \
		${PHASE_MSG} "Regenerating configuration scripts for ${PKGNAME}" && \
		${PERL5} boot && \
		${TOUCH} ${.TARGET}

${WRKDIR}/stamp-prepare-bootstrap: ${WRKDIR}/stamp-autoreconf
	${RUN} cd ${WRKDIR} && \
		${PHASE_MSG} "Preparing bootstrapping compiler for ${PKGNAME}" && \
		${RM} -rf bootstrap && \
		${MKDIR} bootstrap && \
		${GTAR} -cf - ${DISTNAME} | ${GTAR} -C bootstrap -xf - && \
		${CP} ${BOOTSTRAP_MAIN_C} bootstrap/${DISTNAME}/rts/bootstrap-main.c && \
		${CP} ${BOOTSTRAP_CAPI_C} bootstrap/${DISTNAME}/rts/capi-wrappers.c  && \
		${TOUCH} ${.TARGET}

${WRKDIR}/stamp-configure-hc-boot: ${WRKDIR}/stamp-prepare-bootstrap
	${RUN} cd ${WRKDIR}/bootstrap/${DISTNAME} && \
		${PHASE_MSG} "Configuring bootstrapping compiler for ${PKGNAME}" && \
		${SETENV} ${CONFIGURE_ENV} ./configure --enable-hc-boot --with-ghc="" ${CONFIGURE_ARGS} && \
		${TOUCH} ${.TARGET}

${WRKDIR}/stamp-extract-hc: ${WRKDIR}/stamp-configure-hc-boot
	${RUN} cd ${WRKDIR}/bootstrap && \
		${PHASE_MSG} "Extracting bootstrap HC archive for ${PKGNAME}" && \
		if ${TEST} "`${DATE} '+%Y%m%d%H%M'`" -le 200001010000; then \
			${FAIL_MSG} "Adjust your system clock: `${DATE}`"; \
		fi && \
		${FIND} ${DISTNAME} -type d -o -type f | ${XARGS} ${TOUCH} -t 200001010000 && \
		${GTAR} -jxf ${DISTDIR}/${BOOTSTRAP_TARBALL} && \
		(cd ${DISTNAME} && ${SH} mkfiles) && \
		${TOUCH} ${.TARGET}

${WRKDIR}/stamp-rewrite-hc-paths: ${WRKDIR}/stamp-extract-hc
	${RUN} cd ${WRKDIR}/bootstrap/${DISTNAME} && \
		${PHASE_MSG} "Rewriting source paths in bootstrapping compiler for ${PKGNAME}" && \
		${SED} -e "s#\\[\\[PREFIX\\]\\]#${PREFIX}#g" ${BOOTSTRAP_BUILD_MK} > mk/build.mk && \
		for c in libraries/*/configure; do \
			(cd `${DIRNAME} $$c` && ${SETENV} ${CONFIGURE_ENV} ${SH} configure ${CONFIGURE_ARGS}); \
		done && \
		for i in inplace/lib/package.conf.d/*.conf \
				 */package.conf.inplace \
				 */*/package-data.mk \
				 */*/*/package-data.mk \
				 */*/*/*/package-data.mk; do \
			${SED} -e "s#\\[\\[PREFIX\\]\\]#${PREFIX}#g" \
				   -e "s#\\[\\[GHC_SOURCE_PATH\\]\\]#`${PWD_CMD}`#g" $$i > $$i.tmp; \
			${MV} -f $$i.tmp $$i; \
		done && \
		${TOUCH} -r inplace/lib/package.conf.d \
					inplace/lib/package.conf.d/*.conf \
					*/package.conf.inplace \
					*/*/package-data.mk \
					*/*/*/package-data.mk \
					*/*/*/*/package-data.mk \
					compiler/stage?/build/Config.hs && \
		${TOUCH} ${.TARGET}

${WRKDIR}/stamp-bootstrap-ghc: ${WRKDIR}/stamp-rewrite-hc-paths
	${RUN} cd ${WRKDIR}/bootstrap/${DISTNAME} && \
		${PHASE_MSG} "Creating bootstrapping files for ${PKGNAME}" && \
		${BUILD_MAKE_CMD} bootstrapping-files && \
		${PHASE_MSG} "Building bootstrapping compiler for ${PKGNAME}" && \
		${BUILD_MAKE_CMD} all_ghc_stage2 && \
		${PHASE_MSG} "Building bootstrapping toolkit for ${PKGNAME}" && \
		${BUILD_MAKE_CMD} inplace/bin/ghc-pkg && \
		${BUILD_MAKE_CMD} inplace/lib/unlit && \
		inplace/bin/ghc-pkg recache && \
		${CP} -f inplace/bin/ghc-stage2 ${BUILDLINK_DIR}/bin/ghc && \
		${CP} -f inplace/bin/ghc-pkg ${BUILDLINK_DIR}/bin/ghc-pkg && \
		${TOUCH} ${.TARGET}
