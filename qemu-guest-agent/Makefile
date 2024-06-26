# $NetBSD: Makefile,v 1.340 2024/04/07 07:33:58 wiz Exp $

DISTNAME=	qemu-8.2.2
PKGNAME=	${DISTNAME:S/qemu/qemu-guest-agent/}
CATEGORIES=	emulators
MASTER_SITES=	https://download.qemu.org/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.qemu.org/
COMMENT=	CPU emulator using dynamic translation
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit AND modified-bsd

TOOL_DEPENDS+=	meson-[0-9]*:../../devel/meson
TOOL_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

USE_LANGUAGES+=		c c++
#USE_TOOLS+=		bison flex makeinfo perl:build pod2man pkg-config
USE_TOOLS+=		pkg-config perl:build
UNLIMIT_RESOURCES=	datasize
HAS_CONFIGURE=		yes

PATCHDIR=		${.CURDIR}/../../emulators/qemu/patches
RCD_SCRIPTS=		qemu-guest-agent

# https://github.com/qemu/qemu/commit/56208a0d473c6db263cc333c787ca48b502d72ab
GCC_REQD+=		7

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX}/share/qemu
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--python=${PYTHONBIN}
CONFIGURE_ARGS+=	--smbd=${PREFIX}/sbin/smbd
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ENV+=		mansuffix=/${PKGMANDIR}
ALL_ENV+=		MESON_RSP_THRESHOLD=262144

CONFIGURE_ARGS+=	--enable-guest-agent
CONFIGURE_ARGS+=	--disable-tools
CONFIGURE_ARGS+=	--disable-xkbcommon
CONFIGURE_ARGS+=	--disable-attr
CONFIGURE_ARGS+=	--disable-install-blobs
CONFIGURE_ARGS+=	--disable-brlapi
CONFIGURE_ARGS+=	--disable-bzip2
CONFIGURE_ARGS+=	--disable-cap-ng
CONFIGURE_ARGS+=	--disable-coroutine-pool
CONFIGURE_ARGS+=	--disable-curses
CONFIGURE_ARGS+=	--disable-docs
CONFIGURE_ARGS+=	--disable-fdt
CONFIGURE_ARGS+=	--disable-gcrypt
CONFIGURE_ARGS+=	--disable-glusterfs
CONFIGURE_ARGS+=	--disable-libnfs
CONFIGURE_ARGS+=	--disable-libusb
CONFIGURE_ARGS+=	--disable-lzo
CONFIGURE_ARGS+=	--disable-netmap
CONFIGURE_ARGS+=	--disable-nettle
CONFIGURE_ARGS+=	--disable-numa
CONFIGURE_ARGS+=	--disable-rbd
CONFIGURE_ARGS+=	--disable-rdma
CONFIGURE_ARGS+=	--disable-seccomp
CONFIGURE_ARGS+=	--disable-smartcard
CONFIGURE_ARGS+=	--disable-snappy
CONFIGURE_ARGS+=	--disable-spice
CONFIGURE_ARGS+=	--disable-system
CONFIGURE_ARGS+=	--disable-tpm
CONFIGURE_ARGS+=	--disable-user
CONFIGURE_ARGS+=	--disable-vhost-net
CONFIGURE_ARGS+=	--disable-virtfs
CONFIGURE_ARGS+=	--disable-vnc

PKG_SYSCONFSUBDIR=	qemu

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/qemu

TEST_TARGET=		check

PYTHON_FOR_BUILD_ONLY=	tool

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		ninja -j ${_MAKE_JOBS_N:U1} -C build

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} \
		ninja -j ${_MAKE_JOBS_N:U1} -C build install

# Some dependencies aren't correct and this tries to be re-made on install,
# failing due to configure bugs.
post-build:
	${TOUCH} ${WRKSRC}/config-host.mak


.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
