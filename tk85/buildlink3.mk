# $NetBSD: buildlink3.mk,v 1.3 2009/09/20 21:32:24 shindenmorr Exp $

BUILDLINK_TREE+=	tk

.if !defined(TK_BUILDLINK3_MK)
TK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk+=	tk>=8.5.7
BUILDLINK_ABI_DEPENDS.tk+=	tk>=8.5.7
BUILDLINK_PKGSRCDIR.tk?=	../../wip/tk85

BUILDLINK_FILES.tk+=	bin/wish*
#
# Make "-ltk" and "-ltk85" resolve into "-ltk8.5", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tk:tk8.5
BUILDLINK_TRANSFORM+=	l:tk85:tk8.5

TKCONFIG_SH?=	${BUILDLINK_PREFIX.tk}/lib/tk8.5/tkConfig.sh

.include "../../wip/tcl85/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.endif # TK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk
