# $NetBSD$

DISTNAME=	intel-gpu-tools-1.12
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cgit.freedesktop.org/xorg/app/intel-gpu-tools/
COMMENT=	Test & development tools for the intel DRM kernel driver
#LICENSE=	# various, mostly mit-style

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config bash:run

PKGCONFIG_OVERRIDE+=	assembler/intel-gen4asm.pc.in

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64
NOT_FOR_PLATFORM+=	Darwin-*-*

REPLACE_BASH+=	scripts/run-tests.sh
REPLACE_BASH+=	scripts/who.sh
REPLACE_BASH+=	tests/check_drm_clients
REPLACE_BASH+=	tests/ddx_intel_after_fbdev
REPLACE_BASH+=	tests/debugfs_emon_crash
REPLACE_BASH+=	tests/drv_debugfs_reader
REPLACE_BASH+=	tests/drv_missed_irq_hang
REPLACE_BASH+=	tests/drv_module_reload_basic
REPLACE_BASH+=	tests/kms_sysfs_edid_timing
REPLACE_BASH+=	tests/sysfs_l3_parity
REPLACE_BASH+=	tests/test_rte_check
REPLACE_BASH+=	tests/tools_test
REPLACE_BASH+=	tools/intel_aubdump.in

#.include "../../textproc/gtk-doc/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-gtk-doc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	--without-libunwind
.endif

.if ${OPSYS} == "NetBSD"
CFLAGS+=		-Dmmap64=mmap
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
