# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/04/08 07:14:17 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXAW_BUILDLINK3_MK:=	${LIBXAW_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXaw
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXaw}
BUILDLINK_PACKAGES+=	libXaw

.if !empty(LIBXAW_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libXaw+=	libXaw>=1.0.1
BUILDLINK_PKGSRCDIR.libXaw?=	../../wip/libXaw
.endif	# LIBXAW_BUILDLINK3_MK

.include "../../wip/xextproto/buildlink3.mk"
.include "../../wip/libICE/buildlink3.mk"
.include "../../wip/libSM/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXmu/buildlink3.mk"
.include "../../wip/libXpm/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
