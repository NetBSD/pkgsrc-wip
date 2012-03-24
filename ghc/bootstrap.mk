# $NetBSD: bootstrap.mk,v 1.2 2012/03/24 05:03:30 phonohawk Exp $

USE_TOOLS+=	autoconf date gtar perl

# Build an unregisterised bootstrap compiler and install it directly
# into the .buildlink directory. But we can't use "make install"
# because we don't build it in a standard way (./configure && make).
#
# To install it, we just copy ghc and ghc-pkg from
# "work/bootstrap/ghc-${VERSION}/inplace/bin" to
# "${BUILDLINK_DIR}/bin". Note that in-place ghc isn't usable until we
# run "ghc-pkg recache".

BOOTSTRAP_MAIN_C=	${PKGDIR}/files/bootstrap-main.c
BOOTSTRAP_CC_OPTS=	-I${PREFIX:Q}/include
BOOTSTRAP_LD_OPTS=	-L${PREFIX:Q}/lib -Wl,-rpath -Wl,${PREFIX:Q}/lib
BOOTSTRAP_LD_OPTS+=	-lm -liconv -lncurses
BOOTSTRAP_CONF_ARGS=	--enable-hc-boot --with-ghc=""

.if ${MACHINE_ARCH} == "i386" && ${OPSYS} == "NetBSD"
PLATFORM=		i386-unknown-netbsd
BOOTSTRAP_CAPI_C=	${PKGDIR}/files/capi-wrappers-netbsd-i386.c
BOOTSTRAP_TARBALL=	${DISTNAME}-boot-i386-unknown-netbsdelf6.99.1.tar.bz2
# Unregisterised compilers get too large (.text section being over 64
# MiB) without -Os, exceeding NetBSD/i386's kernel default limitation.
BOOTSTRAP_CC_OPTS+=	-Os
BOOTSTRAP_CONF_ARGS+=	CONF_CC_OPTS_STAGE2="-Os"

.elif ${MACHINE_ARCH} == "i386" && ${OPSYS} == "FreeBSD"
PLATFORM=		i386-unknown-freebsd
BOOTSTRAP_CAPI_C=	${PKGDIR}/files/capi-wrappers-freebsd-i386.c
BOOTSTRAP_TARBALL=	${DISTNAME}-boot-i386-unknown-freebsd8.0.tar.bz2
BOOTSTRAP_CC_OPTS+=	-O2
BOOTSTRAP_LD_OPTS+=	-lutil -lrt
BOOTSTRAP_CONF_ARGS+=	CONF_CC_OPTS_STAGE2="-O2"

.elif ${MACHINE_ARCH} == "powerpc" && ${OPSYS} == "Darwin"
PLATFORM=		powerpc-apple-darwin
BOOTSTRAP_CAPI_C=	${PKGDIR}/files/capi-wrappers-darwin-powerpc.c
BOOTSTRAP_TARBALL=	${DISTNAME}-boot-powerpc-apple-darwin9.8.0.tar.bz2
BOOTSTRAP_CC_OPTS+=	-O2
BOOTSTRAP_CONF_ARGS+=	CONF_CC_OPTS_STAGE2="-O2"
# Existence of libelf makes LeadingUnderscore being "NO", which is
# incorrect for this platform. See ghc-6.12.1/aclocal.m4
# (FP_LEADING_UNDERSCORE)
CONFLICTS+=		libelf-[0-9]*

.elif ${MACHINE_ARCH} == "x86_64" && ${OPSYS} == "Linux"
PLATFORM=		x86_64-unknown-linux
BOOTSTRAP_CAPI_C=	${PKGDIR}/files/capi-wrappers-linux-x86_64.c
BOOTSTRAP_TARBALL=	${DISTNAME}-boot-x86_64-unknown-linux-gnu.tar.bz2
BOOTSTRAP_CC_OPTS+=	-O2
BOOTSTRAP_LD_OPTS+=	-lrt -ldl
BOOTSTRAP_CONF_ARGS+=	CONF_CC_OPTS_STAGE2="-O2"

.else
PKG_FAIL_REASON+=	"internal error: unsupported platform"
.endif

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
		${CP} -f ${BOOTSTRAP_MAIN_C:Q} bootstrap/${DISTNAME}/rts/bootstrap-main.c && \
		${CP} -f ${BOOTSTRAP_CAPI_C:Q} bootstrap/${DISTNAME}/rts/capi-wrappers.c  && \
		${TOUCH} ${.TARGET}

${WRKDIR}/stamp-configure-hc-boot: ${WRKDIR}/stamp-prepare-bootstrap
	${RUN} cd ${WRKDIR}/bootstrap/${DISTNAME} && \
		${PHASE_MSG} "Configuring bootstrapping compiler for ${PKGNAME}" && \
		${SETENV} ${CONFIGURE_ENV} ./configure ${BOOTSTRAP_CONF_ARGS} ${CONFIGURE_ARGS} && \
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
		${CP} -f ${PKGDIR:Q}/files/build.bootstrap.common.mk mk/build.mk && \
		${ECHO} "SRC_CC_OPTS += ${BOOTSTRAP_CC_OPTS}" >> mk/build.mk && \
		${ECHO} "LD_OPTS += ${BOOTSTRAP_LD_OPTS}" >> mk/build.mk && \
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
