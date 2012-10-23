# $NetBSD: buildlink3.mk,v 1.3 2012/10/23 00:14:43 othyro Exp $

BUILDLINK_TREE+=	tk86

.if !defined(TK86_BUILDLINK3_MK)
TK86_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk86+=	tk86>=8.6
BUILDLINK_ABI_DEPENDS.tk86+=	tk86>=8.6
BUILDLINK_PKGSRCDIR.tk86?=	../../wip/tk86
TKCONFIG_SH_DIR?=        ${BUILDLINK_PREFIX.tk86}/lib

BUILDLINK_FILES.tk86+=	bin/wish*
#
# Make "-ltk" and "-ltk86" resolve into "-ltk8.6", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tk:tk8.6
BUILDLINK_TRANSFORM+=	l:tk86:tk8.6

TKCONFIG_SH?=	${TKCONFIG_SH_DIR}/tk8.6/tkConfig.sh

.include "../../wip/tcl86/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.endif # TK86_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk86
