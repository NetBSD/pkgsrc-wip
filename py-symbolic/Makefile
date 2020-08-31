# $NetBSD$

DISTNAME=	symbolic-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/symbolic/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/getsentry/symbolic/
COMMENT=	Library for dealing with symbol files and more
LICENSE=	mit

MAKE_ENV+=	RUSTFLAGS="-Clink-arg=${COMPILER_RPATH_FLAG}${PREFIX}/lib"

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

DEPENDS+=       ${PYPKGPREFIX}-milksnake>=0.1.5:../../wip/py-milksnake
DEPENDS+=       ${PYPKGPREFIX}-cffi>=1.11.5:../../devel/py-cffi
DEPENDS+=       ${PYPKGPREFIX}-cparser>=2.18:../../devel/py-cparser
BUILD_DEPENDS+=         cmake-[0-9]*:../../devel/cmake
.include "../../mk/bsd.prefs.mk"

#HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--python=${PYTHONBIN}
CONFIGURE_ARGS+=	--release-channel=stable
CONFIGURE_ARGS+=	--enable-local-rust
CONFIGURE_ARGS+=	--local-rust-root=${RUST_BOOTSTRAP_PATH}
CONFIGURE_ARGS+=	--enable-extended       # Build and install cargo too.
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--disable-codegen-tests
CONFIGURE_ARGS+=	--disable-dist-src
CONFIGURE_ARGS+=	--disable-llvm-static-stdcpp
CONFIGURE_ARGS+=	--disable-ninja
CONFIGURE_ARGS+=	--enable-vendor

CONFIGURE_ARGS+=	--rustc=${PREFIX}/bin/rustc
CONFIGURE_ARGS+=	--rustdoc=${PREFIX}/bin/rustdoc
MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
MAKE_ENV+=		LIBGIT2_SYS_USE_PKG_CONFIG=1
MAKE_ENV+=		VERBOSE=1

UNLIMIT_RESOURCES+=	cputime

#PYSETUP=	setup.py
PYTHON_VERSIONS_ACCEPTED= 27

CHECK_RELRO_SUPPORTED=	no

GCC_REQD+=		4.8
USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++ c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		bash gmake perl:build pkg-config

CMAKE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

BUILDLINK_TRANSFORM.NetBSD+=	rm:-Wl,--enable-new-dtags

.if ${OPSYS} == "FreeBSD"
MAKE_ENV+=		OPENSSL_DIR=${SSLBASE}
.endif

OPSYSVARS+=		SOEXT
SOEXT.Darwin=		dylib
SOEXT.*=		so

EGG_NAME?=		${DISTNAME}
EGG_INFODIR?=		${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
PLIST_SUBST+=		PYSITELIB=${PYSITELIB}
PLIST_SUBST+=		EGG_NAME=${EGG_NAME}-py${PYVERSSUFFIX}
PLIST_SUBST+=		EGG_INFODIR=${EGG_INFODIR}

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py install

.include "../../lang/python27/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../lang/python/tool.mk"
#.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.rust+=     rust>=1.25.0
.include "../../lang/rust/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
