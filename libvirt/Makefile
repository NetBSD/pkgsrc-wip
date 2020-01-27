# $NetBSD: Makefile,v 1.68 2019/09/02 13:20:09 adam Exp $

DISTNAME=		libvirt-5.8.0
CATEGORIES=		sysutils
MASTER_SITES=		http://libvirt.org/sources/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://libvirt.org/
COMMENT=		Virtualisation toolkit for host operating systems
LICENSE=		gnu-lgpl-v2

TOOL_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt

USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR} --localstatedir=${VARBASE}
CONFIGURE_ARGS+=	PYTHON=${PYTHONBIN}
TEST_TARGET=		check
RCD_SCRIPTS=		libvirtd

SUBST_CLASSES+=			reserved-name
SUBST_STAGE.reserved-name=	pre-configure
SUBST_FILES.reserved-name=	src/qemu/qemu_process.h src/qemu/qemu_process.c
SUBST_SED.reserved-name=	-e 's|stderr|qemu_stderr|g'

PKGCONFIG_OVERRIDE+=	libvirt.pc.in
PKGCONFIG_OVERRIDE+=	libvirt-admin.pc.in
PKGCONFIG_OVERRIDE+=	libvirt-lxc.pc.in
PKGCONFIG_OVERRIDE+=	libvirt-qemu.pc.in

AUTO_MKDIRS=		yes
EGDIR=			${PREFIX}/share/examples
CONF_FILES+=		${EGDIR}/libvirt/libvirt-admin.conf ${PKG_SYSCONFDIR}/libvirt/libvirt-admin.conf
CONF_FILES+=		${EGDIR}/libvirt/libvirt.conf ${PKG_SYSCONFDIR}/libvirt/libvirt.conf
CONF_FILES+=		${EGDIR}/libvirt/libvirtd.conf ${PKG_SYSCONFDIR}/libvirt/libvirtd.conf
CONF_FILES+=		${EGDIR}/libvirt/qemu/networks/autostart/default.xml ${PKG_SYSCONFDIR}/libvirt/qemu/networks/autostart/default.xml
CONF_FILES+=		${EGDIR}/libvirt/qemu/networks/default.xml ${PKG_SYSCONFDIR}/libvirt/qemu/networks/default.xml
CONF_FILES+=		${EGDIR}/libvirt/virtlockd.conf ${PKG_SYSCONFDIR}/libvirt/virtlockd.conf
CONF_FILES+=		${EGDIR}/libvirt/virtlogd.conf ${PKG_SYSCONFDIR}/libvirt/virtlogd.conf
CONF_FILES+=		${EGDIR}/logrotate.d/libvirtd ${PKG_SYSCONFDIR}/libvirtlogrotate.d/libvirtd
CONF_FILES+=		${EGDIR}/logrotate.d/libvirtd.libxl ${PKG_SYSCONFDIR}/libvirtlogrotate.d/libvirtd.libxl
CONF_FILES+=		${EGDIR}/logrotate.d/libvirtd.lxc ${PKG_SYSCONFDIR}/libvirtlogrotate.d/libvirtd.lxc
CONF_FILES+=		${EGDIR}/logrotate.d/libvirtd.qemu ${PKG_SYSCONFDIR}/libvirtlogrotate.d/libvirtd.qemu

CONFIGURE_ARGS.NetBSD+=	--with-qemu-group=wheel

.include "../../devel/yajl/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
