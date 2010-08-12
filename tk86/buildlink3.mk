# $NetBSD: buildlink3.mk,v 1.1 2010/08/12 05:59:55 bharder Exp $

BUILDLINK_TREE+=	tk86

.if !defined(TK86_BUILDLINK3_MK)
TK86_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk86+=	tk86>=8.6
BUILDLINK_ABI_DEPENDS.tk86+=	tk86>=8.6
BUILDLINK_PKGSRCDIR.tk86?=	../../wip/tk86

BUILDLINK_FILES.tk86+=	bin/wish*
#
# Make "-ltk" and "-ltk86" resolve into "-ltk8.6", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tk:tk8.6
BUILDLINK_TRANSFORM+=	l:tk86:tk8.6

TKCONFIG_SH?=	${BUILDLINK_PREFIX.tk}/lib/tk8.6/tkConfig.sh

.include "../../wip/tcl86/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.endif # TK86_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk86
