# $NetBSD$

DISTNAME=	et-6.2.8
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=MisterTea/}
GITHUB_PROJECT=	EternalTerminal
GITHUB_TAG=	et-v${PKGVERSION_NOREV}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MisterTea/EternalTerminal/
COMMENT=	Remote shell to automatically reconnect
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/EternalTerminal-${GITHUB_TAG}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl
GCC_REQD+=	9  # uses std::filesystem

CMAKE_CONFIGURE_ARGS+=	-DDISABLE_VCPKG=ON
CMAKE_CONFIGURE_ARGS+=	-DDISABLE_TELEMETRY=ON

PKGCONFIG_OVERRIDE+=	external_imported/Catch2/CMake/catch2.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/UniversalStacktrace/external/Catch2/CMake/catch2.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/json/benchmarks/thirdparty/benchmark/cmake/benchmark.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/json/cmake/pkg-config.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/msgpack-c/msgpack.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/sentry-native/external/breakpad/breakpad-client.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/sentry-native/external/breakpad/breakpad.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/bzip2/bzip2.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/libvpx/vpx.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/openssl/openssl.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/sqlite3/sqlite3.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/szip/szip.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/v8/v8.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/v8/v8_libbase.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/v8/v8_libplatform.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/v8/v8_monolith.pc.in

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/catch2/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../devel/cxxopts/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
