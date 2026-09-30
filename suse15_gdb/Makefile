# $NetBSD: Makefile,v 1.3 2026/07/03 10:04:41 sborrill Exp $

PKGNAME=	suse_gdb-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	babeltrace-1.5.8-1.30.${SUSE_ARCH}
RPMPKGS+=	gdb-12.1-150400.15.6.1.${SUSE_ARCH}
RPMPKGS+=	gdbserver-12.1-150400.15.6.1.${SUSE_ARCH}
RPMPKGS+=	krb5-1.20.1-150500.1.2.${SUSE_ARCH}
RPMPKGS+=	libboost_regex1_66_0-1.66.0-12.3.1.${SUSE_ARCH}
RPMPKGS+=	libbrotlicommon1-1.0.7-3.3.1.${SUSE_ARCH}
RPMPKGS+=	libbrotlidec1-1.0.7-3.3.1.${SUSE_ARCH}
RPMPKGS+=	libcom_err2-1.46.4-150400.3.3.1.${SUSE_ARCH}
RPMPKGS+=	libcurl4-7.79.1-150400.5.18.1.${SUSE_ARCH}
RPMPKGS+=	libdebuginfod1-0.185-150400.5.3.1.${SUSE_ARCH}
RPMPKGS+=	libdw1-0.185-150400.5.3.1.${SUSE_ARCH}
RPMPKGS+=	libicu-suse65_1-65.1-150200.4.5.1.${SUSE_ARCH}
RPMPKGS+=	libidn2-0-2.2.0-3.6.1.${SUSE_ARCH}
RPMPKGS+=	libjitterentropy3-3.4.0-150000.1.9.1.${SUSE_ARCH}
RPMPKGS+=	libldap-2_4-2-2.4.46-150200.14.11.2.${SUSE_ARCH}
RPMPKGS+=	liblua5_3-5-5.3.6-3.6.1.${SUSE_ARCH}
RPMPKGS+=	libnghttp2-14-1.40.0-6.1.${SUSE_ARCH}
RPMPKGS+=	libopenssl1_1-1.1.1l-150500.15.4.${SUSE_ARCH}
RPMPKGS+=	libpopt0-1.16-3.22.${SUSE_ARCH}
RPMPKGS+=	libpsl5-0.20.1-150000.3.3.1.${SUSE_ARCH}
RPMPKGS+=	libpython3_6m1_0-3.6.15-150300.10.45.1.${SUSE_ARCH}
RPMPKGS+=	libsasl2-3-2.1.28-150500.1.1.${SUSE_ARCH}
RPMPKGS+=	libsource-highlight4-3.1.8-150000.3.4.1.${SUSE_ARCH}
RPMPKGS+=	libssh4-0.9.6-150400.1.5.${SUSE_ARCH}
RPMPKGS+=	libunistring2-0.9.10-1.1.${SUSE_ARCH}
RPMPKGS+=	python3-base-3.6.15-150300.10.45.1.${SUSE_ARCH}
RPMPKGS+=	rpm-4.14.3-150300.55.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for GNU GDB 12

EMUL_MODULES.linux=	base binutils expat freetype2 gcc12 glib2 glx

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
