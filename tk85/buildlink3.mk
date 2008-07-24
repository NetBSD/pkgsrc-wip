# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/07/24 19:35:09 egavilan Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TK_BUILDLINK3_MK:=	${TK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntk}
BUILDLINK_PACKAGES+=	tk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}tk

.if !empty(TK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.tk+=	tk>=8.5.3
BUILDLINK_ABI_DEPENDS.tk+=	tk>=8.5.3
BUILDLINK_PKGSRCDIR.tk?=	../../wip/tk85

BUILDLINK_FILES.tk+=	bin/wish*
#
# Make "-ltk" and "-ltk85" resolve into "-ltk8.5", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tk:tk8.5
BUILDLINK_TRANSFORM+=	l:tk85:tk8.5

TKCONFIG_SH?=	${BUILDLINK_PREFIX.tk}/lib/tk8.5/tkConfig.sh
.endif	# TK_BUILDLINK3_MK

.include "../../wip/tcl85/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
