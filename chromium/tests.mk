# $NetBSD$

REGRESS_DISTFILE=		chromium-${VERSION}-testdata${EXTRACT_SUFX}
FONTS_DISTFILE=			test_fonts-336e775eec536b2d785cc80eff6ac39051931286.tar.gz
SITES.${FONTS_DISTFILE}=	http://nerd.hu/distfiles/
DISTFILES+=			${REGRESS_DISTFILE}
DISTFILES+=			${FONTS_DISTFILE}
EXTRACT_ONLY=			${DISTNAME}${EXTRACT_SUFX} ${PROFILE_DISTFILE}

USE_TOOLS+=	xzcat gzip tar

#TEST_ENV+=	FONTCONFIG_SYSROOT=${WRKSRC}/third_party/test_fonts

TEST_TARGET=	base_unittests
TEST_TARGET+=	blink_unittests
TEST_TARGET+=	chromedriver_unittests

# third_party/crashpad/crashpad/handler/handler_main.cc: error:
# use of undeclared identifier 'ReinstallCrashHandler'
# use of undeclared identifier 'InstallCrashHandler'
# use of undeclared identifier 'CrashReportExceptionHandler'
# use of undeclared identifier 'exception_handler_server'
#TEST_TARGET+=	components_unittests

TEST_TARGET+=	content_unittests
TEST_TARGET+=	crypto_unittests
TEST_TARGET+=	gl_tests
TEST_TARGET+=	gpu_unittests
TEST_TARGET+=	headless_unittests
TEST_TARGET+=	media_unittests

# third_party/ipcz/src/reference_drivers/wrapped_file_descriptor.h:
# no member named 'kFileDescriptor' in 'ipcz::reference_drivers::Object'
#TEST_TARGET+=	mojo_unittests

TEST_TARGET+=	net_unittests
TEST_TARGET+=	pdf_unittests

# printing/mojom/printing_context_mojom_traits_unittest.cc:88:2:
# error: "System print dialog support not implemented for this platform."
#TEST_TARGET+=	printing_unittests

TEST_TARGET+=	skia_unittests
TEST_TARGET+=	url_unittests
TEST_TARGET+=	wm_unittests

pre-test:
	@${ECHO_MSG} "=> Extracting ${REGRESS_DISTFILE}"
	${XZCAT} ${DISTDIR}/${REGRESS_DISTFILE} | ${TAR} -C ${WRKDIR} -xf -
	@${ECHO_MSG} "=> Extracting ${FONTS_DISTFILE}"
	${GZIP_CMD} -dc ${DISTDIR}/${FONTS_DISTFILE} | ${TAR} -C ${WRKSRC}/third_party/test_fonts -xf -
	${MKDIR} ${WRKSRC}/third_party/llvm-build/Release+Asserts/bin
	${LN} -sf ${PREFIX}/bin/clang++ ${WRKSRC}/third_party/llvm-build/Release+Asserts/bin/clang++
	${LN} -sf ${PREFIX}/bin/clang ${WRKSRC}/third_party/llvm-build/Release+Asserts/bin/clang
	${LN} -sf ${PREFIX}/bin/llvm-ar ${WRKSRC}/third_party/llvm-build/Release+Asserts/bin/llvm-ar

do-test:
.for t in ${TEST_TARGET}
	@${ECHO_MSG} "=> Test target: ${t}"
	cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} ${PREFIX}/bin/ninja -j ${MAKE_JOBS:U1} -C out/${BUILDTYPE} ${t}
.endfor
