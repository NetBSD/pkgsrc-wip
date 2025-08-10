# $NetBSD: build.mk,v 1.24 2025/05/01 12:31:45 wiz Exp $
#
# This Makefile fragment supports building using the CMake build tool.
#
# It is not a buildlink3 file, and thus should not be sorted among bl3
# files.  It should be included before all bl3 files, because it sets
# a variable (BUILD_USES_CMAKE) that can alter bl3 behavior.  The
# variable CMAKE_GENERATOR must be defined before inclusion (as it is
# a user-settable variable that should happen automatically).
#
# User-settable variables:
#
# CMAKE_GENERATOR
#	Which build tool to use.
#
#	Possible: make ninja
#	Default: make
#
# Package-settable variables:
#
# CMAKE_CONFIGURE_ARGS
#	Arguments to pass to CMake during the configure stage.
#
# CMAKE_BUILD_ARGS
#	Arguments to pass to CMake during build. Default: empty
#
# CMAKE_INSTALL_ARGS
#	Arguments to pass to CMake during installation: Default: empty
#
# CMAKE_GENERATORS_INCOMPATIBLE
#	CMAKE_GENERATORS that will not work with this package. (A typical
#	case is ninja failing with BUILD_DIRS set to a subdirectory.)
#
# CONFIGURE_DIR
#	Directory relative to WRKSRC in which to run CMake. Usually
#	the top-level one.
#
# BUILD_DIRS
#	Directories relative to WRKSRC/CMAKE_BUILD_DIR in which to build.
#	Defaults to WRKSRC/CMAKE_BUILD_DIR.
#
# TEST_DIRS
#	Directories relative to WRKSRC/CMAKE_BUILD_DIR in which to run the
#	tests. Defaults to BUILD_DIRS.
#
# INSTALL_DIRS
#	Directories relative to WRKSRC/CMAKE_BUILD_DIR in which to run the
#	'install' step. Defaults to BUILD_DIRS.

.include "../../mk/bsd.fast.prefs.mk"

CMAKE_REQD?=	0
.for version in ${CMAKE_REQD}
TOOL_DEPENDS+=	cmake>=${version}:../../devel/cmake
.endfor

# Declare that this package is using cmake, for bl3 files to know
# to add to CMAKE_CONFIGURE_ARGS.
BUILD_USES_CMAKE=	yes

OPSYSVARS+=		CMAKE_CONFIGURE_ARGS

# The assumption in pkgsrc is that packages don't download files
# mid-build.
CMAKE_CONFIGURE_ARGS+=	-DFETCHCONTENT_FULLY_DISCONNECTED=ON

# Ensure cmake only looks in system files or in the sanitized buildlink
# directory for find_package/program/library/file/path.
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_FIND_USE_CMAKE_SYSTEM_PATH:BOOL=OFF
CMAKE_PREFIX_PATH+=	${BUILDLINK_DIR}
.if ${OPSYS} == "Darwin"
CMAKE_PREFIX_PATH+=	${OSX_SDK_PATH}/System/Library/Frameworks
.endif
CMAKE_INCLUDE_PATH+=	${COMPILER_INCLUDE_DIRS:@.d.@${_CROSS_DESTDIR:U}${.d.}@}
CMAKE_LIBRARY_PATH+=	${COMPILER_LIB_DIRS:@.d.@${_CROSS_DESTDIR:U}${.d.}@}

CONFIGURE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}

CMAKE_BUILD_DIR?=	cmake-pkgsrc-build
CMAKE_BUILD_ARGS?=	-j ${_MAKE_JOBS_N:U1}
CMAKE_INSTALL_ARGS?=	-j ${_MAKE_JOBS_N:U1}

CMAKE_GENERATORS_INCOMPATIBLE?=	# empty

.for cg in ${CMAKE_GENERATOR} make ninja
.  if empty(CMAKE_GENERATORS_INCOMPATIBLE:M${cg})
_CMAKE_GENERATOR?=	${cg}
.  endif
.endfor
_CMAKE_GENERATOR?=	none
.if ${_CMAKE_GENERATOR} == "ninja"
TOOL_DEPENDS+=		ninja-build-[0-9]*:../../devel/ninja-build
_CMAKE_BUILD_SYSTEM?=	Ninja
_CMAKE_BUILD_TOOL?=	ninja
.elif ${_CMAKE_GENERATOR} == "make"
_CMAKE_BUILD_SYSTEM?=	Unix Makefiles
_CMAKE_BUILD_TOOL?=	${MAKE_PROGRAM}
.else
PKG_FAIL_REASON+=	"No valid cmake generator found."
.endif

CONFIGURE_DIR?=		.
BUILD_DIRS?=		.
TEST_DIRS?=		${BUILD_DIRS}
INSTALL_DIRS?=		${BUILD_DIRS}

_CMAKE_CONFIGURE_SETTINGS=	yes

.PHONY: cmake-configure cmake-build cmake-test cmake-install

.if !target(do-configure)
do-configure: cmake-configure
cmake-configure:
	${RUN} cd ${WRKSRC}/${CONFIGURE_DIR} && \
		${SETENV} ${CONFIGURE_ENV} cmake \
		--install-prefix ${PREFIX} \
		-B ${CMAKE_BUILD_DIR} \
		-G ${_CMAKE_BUILD_SYSTEM:Q} \
		${CMAKE_CONFIGURE_ARGS}
.endif

.if !target(do-build)
do-build: cmake-build
cmake-build:
.  for d in ${BUILD_DIRS}
	${RUN} cd ${WRKSRC}/${CONFIGURE_DIR}/${CMAKE_BUILD_DIR}/${d} && \
		${SETENV} ${MAKE_ENV} \
		${_CMAKE_BUILD_TOOL} ${CMAKE_BUILD_ARGS} ${BUILD_TARGET}
.  endfor
.endif

.if !target(do-test)
do-test: cmake-test
cmake-test:
.  for d in ${TEST_DIRS}
	${RUN} cd ${WRKSRC}/${CONFIGURE_DIR}/${CMAKE_BUILD_DIR}/${d} && \
		${SETENV} ${TEST_ENV} \
		${_CMAKE_BUILD_TOOL} ${CMAKE_BUILD_ARGS} ${TEST_TARGET}
.  endfor
.endif

.if !target(do-install)
do-install: cmake-install
cmake-install:
.  for d in ${INSTALL_DIRS}
	${RUN} cd ${WRKSRC}/${CONFIGURE_DIR}/${CMAKE_BUILD_DIR}/${d} && \
		${SETENV} ${INSTALL_ENV} \
		${_CMAKE_BUILD_TOOL} ${CMAKE_INSTALL_ARGS} ${INSTALL_TARGET}
.  endfor
.endif

_VARGROUPS+=		cmake
_USER_VARS.cmake+=	CMAKE_GENERATOR
_PKG_VARS.cmake+=	CMAKE_REQD
_PKG_VARS.cmake+=	CMAKE_CONFIGURE_ARGS CONFIGURE_DIR
_PKG_VARS.cmake+=	CMAKE_BUILD_ARGS BUILD_DIRS BUILD_TARGET
_PKG_VARS.cmake+=	TEST_DIRS TEST_TARGET
_PKG_VARS.cmake+=	CMAKE_INSTALL_ARGS INSTALL_DIRS INSTALL_TARGET
_PKG_VARS.cmake+=	CMAKE_GENERATORS_INCOMPATIBLE _CMAKE_GENERATOR
_SYS_VARS.cmake+=	CMAKE_BUILD_DIR
_USE_VARS.cmake+=	CONFIGURE_ENV MAKE_ENV TEST_ENV INSTALL_ENV
_IGN_VARS.cmake+=	BUILDLINK_DIR WRKSRC PREFIX
_IGN_VARS.cmake+=	BUILD_USES_CMAKE SETENV TOOL_DEPENDS
_IGN_VARS.cmake+=	_CMAKE_BUILD_SYSTEM _CMAKE_BUILD_TOOL _MAKE_JOBS_N
_IGN_VARS.cmake+=	_CMAKE_CONFIGURE_SETTINGS
_LISTED_VARS.cmake+=	*_ARGS
_SORTED_VARS.cmake+=	*_ENV
