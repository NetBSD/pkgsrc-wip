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

# Backends
CONFIGURE_ARGS+=	--with-bhyve=check
CONFIGURE_ARGS+=	--with-esx=no
CONFIGURE_ARGS+=	--with-hyperv=no
CONFIGURE_ARGS+=	--with-openvz=no	# Linux only
CONFIGURE_ARGS+=	--with-qemu=yes
CONFIGURE_ARGS+=	--with-vbox=yes
CONFIGURE_ARGS+=	--with-vmware=yes

# Libraries
CONFIGURE_ARGS+=	--with-apparmor=no
CONFIGURE_ARGS+=	--with-attr=no
CONFIGURE_ARGS+=	--with-blkid=no
CONFIGURE_ARGS+=	--with-capng=no
CONFIGURE_ARGS+=	--with-curl=no
CONFIGURE_ARGS+=	--with-dbus=no
CONFIGURE_ARGS+=	--with-dtrace=no
CONFIGURE_ARGS+=	--with-firewalld=no
CONFIGURE_ARGS+=	--with-fuse=no
CONFIGURE_ARGS+=	--with-glusterfs=no
CONFIGURE_ARGS+=	--with-hal=no
CONFIGURE_ARGS+=	--with-interface=no
CONFIGURE_ARGS+=	--with-libiscsi=no
CONFIGURE_ARGS+=	--with-libpcap=no
CONFIGURE_ARGS+=	--with-libssh=no
CONFIGURE_ARGS+=	--with-libxl=no
CONFIGURE_ARGS+=	--with-libxml=yes
CONFIGURE_ARGS+=	--with-lxc=no		# Linux only
CONFIGURE_ARGS+=	--with-macvtap=no	# Linux only
CONFIGURE_ARGS+=	--with-netcf=no
# TODO: missing in Void w/ musl?
CONFIGURE_ARGS+=	--with-nss-plugin=no
CONFIGURE_ARGS+=	--with-numactl=no
CONFIGURE_ARGS+=	--with-numad=no
CONFIGURE_ARGS+=	--with-openwsman=no
CONFIGURE_ARGS+=	--with-pciaccess=no
CONFIGURE_ARGS+=	--with-phyp=no
CONFIGURE_ARGS+=	--with-pm-utils=yes
CONFIGURE_ARGS+=	--with-polkit=no
# TODO: yes with option readline
CONFIGURE_ARGS+=	--with-readline=no
CONFIGURE_ARGS+=	--with-sanlock=no
CONFIGURE_ARGS+=	--with-sasl=no
CONFIGURE_ARGS+=	--with-selinux-mount=no
CONFIGURE_ARGS+=	--with-selinux=no
CONFIGURE_ARGS+=	--with-ssh2=no
CONFIGURE_ARGS+=	--with-udev=no
CONFIGURE_ARGS+=	--with-virtualport=no	# Linux only
CONFIGURE_ARGS+=	--with-vz=no
CONFIGURE_ARGS+=	--with-yajl=yes

# Storage
CONFIGURE_ARGS+=	--with-storage-disk=no
# TODO: breaks Void build. Needs mntent.h.
CONFIGURE_ARGS+=	--with-storage-fs=no
CONFIGURE_ARGS+=	--with-storage-gluster=no
CONFIGURE_ARGS+=	--with-storage-iscsi-direct=no
CONFIGURE_ARGS+=	--with-storage-iscsi=no
CONFIGURE_ARGS+=	--with-storage-lvm=no	# Linux only
CONFIGURE_ARGS+=	--with-storage-mpath=no	# Linux only
CONFIGURE_ARGS+=	--with-storage-rbd=no
CONFIGURE_ARGS+=	--with-storage-scsi=yes
CONFIGURE_ARGS+=	--with-storage-sheepdog=no
CONFIGURE_ARGS+=	--with-storage-vstorage=no
CONFIGURE_ARGS+=	--with-storage-zfs=no

# Security drivers
CONFIGURE_ARGS+=	--with-secdriver-linux=no
CONFIGURE_ARGS+=	--with-secdriver-apparmor=no

# Misc
# TODO: yes with option readline
CONFIGURE_ARGS+=	--with-bash-completion=no
CONFIGURE_ARGS+=	--with-host-validate=yes
CONFIGURE_ARGS+=	--with-init-script=check
CONFIGURE_ARGS+=	--with-login-shell=no	# Linux only
CONFIGURE_ARGS+=	--with-sysctl=check
CONFIGURE_ARGS+=	--with-wireshark-dissector=no

CONFIGURE_ARGS.NetBSD+=	--with-qemu-group=wheel

CONFIGURE_ARGS.Linux+=	--with-lxc=yes
CONFIGURE_ARGS.Linux+=	--with-macvtap=yes
CONFIGURE_ARGS.Linux+=	--with-virtualport=yes
CONFIGURE_ARGS.Linux+=	--with-login-shell=yes
CONFIGURE_ARGS.Linux+=	--with-storage-lvm=yes
CONFIGURE_ARGS.Linux+=	--with-storage-mpath=yes
# Unit files for all distros, harmless for other inits.
CONFIGURE_ARGS.Linux+=	--with-init-script=systemd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.include "../../wip/libnl1/buildlink3.mk"
.include "../../wip/lvm2/buildlink3.mk"
.include "../../wip/portablexdr/buildlink3.mk"
.endif

.include "../../devel/yajl/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
