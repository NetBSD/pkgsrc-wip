# $NetBSD$

DISTNAME=		AirConnect-1.8.3
PKGNAME=		${DISTNAME:tl}
CATEGORIES=		audio net
MASTER_SITES=		${MASTER_SITE_GITHUB:=philippe44/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/philippe44/AirConnect/
COMMENT=		AirPlay bridge to UPnP/Sonos and Chromecast
LICENSE=		mit

GITHUB_SUBMODULES+=	nanopb nanopb ea54d265a96e5f2bf8d1e1aa1e2ca70dfcc75d0b aircast/nanopb
GITHUB_SUBMODULES+=	philippe44 crosstools 8b0081f88b669c6918b85979188b3859ca430e5e common/crosstools
GITHUB_SUBMODULES+=	philippe44 dmap-parser 2f8ee61e2427a177beea919d72dde8931084fe51 common/dmap-parser
GITHUB_SUBMODULES+=	philippe44 libcodecs fb2cf6b096cce2e630f0c05174ab3aa9bd3503c1 common/libcodecs
GITHUB_SUBMODULES+=	philippe44 libmdns d7f58bf2791c3c25fd729d739a9267ce9db5b696 common/libmdns
GITHUB_SUBMODULES+=	philippe44 libpthreads4w 2ae750783281db5b5cd867649880b3b951ced781 common/libpthreads4w
GITHUB_SUBMODULES+=	philippe44 libpupnp 11a9750e2fa6da392345fcc8868b307444e13341 common/libpupnp
GITHUB_SUBMODULES+=	philippe44 libraop 09c64996fa863f5f327ea441030fe20e48092121 common/libraop

USE_TOOLS+=		pax bash gmake

TOOL_DEPENDS+=		bash>=4.0:../../shells/bash
TOOLS_PLATFORM.bash=	${PREFIX}/bin/bash

# Map pkgsrc platform variables to AirConnect's naming conventions
AC_ARCH=		${MACHINE_ARCH:S/aarch64/arm64/:S/i386/x86/:S/amd64/x86_64/}
AC_OS=			${OPSYS:tl:S/darwin/macos/:S/netbsd/freebsd/}
AC_COMPILER=		${AC_ARCH}-${AC_OS}-${OPSYS:Mdarwin:?cc:gcc}
AC_BINDIR=		${AC_OS}/${AC_ARCH}
BASH_SCRIPTS=		aircast/nanopb/tools/list_authors.sh
BASH_SCRIPTS+=		aircast/nanopb/tools/make_mac_package.sh
BASH_SCRIPTS+=		aircast/nanopb/tools/set_version.sh
BASH_SCRIPTS+=		aircast/nanopb/tools/make_windows_package.sh
BASH_SCRIPTS+=		aircast/nanopb/tools/make_linux_package.sh
BASH_SCRIPTS+=		aircast/nanopb/extra/poetry/poetry_build.sh
BASH_SCRIPTS+=		updater
BASH_SCRIPTS+=		common/libcodecs/build.sh
BASH_SCRIPTS+=		common/libmdns/build.sh
BASH_SCRIPTS+=		common/libpupnp/build.sh
BASH_SCRIPTS+=		common/libraop/build.sh
BASH_SCRIPTS+=		build.sh

REPLACE_BASH+=		${BASH_SCRIPTS}

INSTALLATION_DIRS=	bin

BUILDLINK_TRANSFORM+=	rm:-fno-temp-file

post-extract:
	cd ${WRKDIR} && mv ${DISTNAME} ${PKGNAME_NOREV}
	# Fix nested directory structure on case-sensitive filesystems
	if [ -d ${WRKSRC}/${DISTNAME} ]; then \
		cd ${WRKSRC}/${DISTNAME} && ${PAX} -rw . ${WRKSRC}/; \
		cd ${WRKSRC} && ${RM} -rf ${DISTNAME}; \
	fi
	cd ${WRKSRC} && ${CHMOD} +x ${BASH_SCRIPTS}
.if !exists(${WRKSRC}/common/libpupnp/targets/${AC_OS}/${AC_ARCH})
	cd ${WRKSRC}/common/libpupnp; \
	${MKDIR} targets/${AC_OS}; \
	${CP} -Rp targets/freebsd/x86_64 targets/${AC_OS}/${AC_ARCH}
.endif

do-configure:
	# Create fake cross-compiler to match build system expectations
	${MKDIR} ${WRKSRC}/.fake-cc
	cd ${WRKSRC}/.fake-cc && ${PRINTF} '#!/bin/sh\nexec %s "$$@"\n' 'cc' > ${AC_COMPILER}
	cd ${WRKSRC}/.fake-cc && ${PRINTF} '#!/bin/sh\nexec %s "$$@"\n' 'c++' > ${AC_COMPILER:S/cc$/c++/:S/gcc$/g++/}
	${CHMOD} +x ${WRKSRC}/.fake-cc/*

do-build:
	# Create necessary output directories
	${MKDIR} ${WRKSRC}/bin/${AC_BINDIR}
	# Build dynamic versions using pkgsrc's wrapped compilers
	cd ${WRKSRC}/airupnp && ${SETENV} ${MAKE_ENV} CC=${WRKSRC}/.fake-cc/${AC_COMPILER} HOST=${AC_OS} PLATFORM=${AC_ARCH} ${GMAKE} ../bin/airupnp-${AC_OS}-${AC_ARCH}
	cd ${WRKSRC}/aircast && ${SETENV} ${MAKE_ENV} CC=${WRKSRC}/.fake-cc/${AC_COMPILER} HOST=${AC_OS} PLATFORM=${AC_ARCH} ${GMAKE} ../bin/aircast-${AC_OS}-${AC_ARCH}
	# Create the universal binaries that the install expects
	#cd ${WRKSRC}/bin && ln -sf airupnp-${AC_OS}-${AC_ARCH} airupnp-${AC_OS}
	#cd ${WRKSRC}/bin && ln -sf aircast-${AC_OS}-${AC_ARCH} aircast-${AC_OS}

do-install:
	cd ${WRKSRC}/bin; \
	${INSTALL_PROGRAM} airupnp-${AC_OS}-${AC_ARCH} ${DESTDIR}${PREFIX}/bin/airupnp; \
	${INSTALL_PROGRAM} aircast-${AC_OS}-${AC_ARCH} ${DESTDIR}${PREFIX}/bin/aircast

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
