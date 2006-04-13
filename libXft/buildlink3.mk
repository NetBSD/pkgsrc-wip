# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/04/13 02:18:59 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXFT_BUILDLINK3_MK:=	${LIBXFT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		libXft
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXft}
BUILDLINK_PACKAGES+=	libXft

.if !empty(LIBXFT_BUILDLINK3_MK:M+)
BUILDLINK_ABI_DEPENDS.libXft+=	libXft>=2.1
BUILDLINK_API_DEPENDS.libXft+=	libXft>=2.1.7nb2
BUILDLINK_PKGSRCDIR.libXft?=	../../wip/libXft
.endif	# LIBXFT_BUILDLINK3_MK

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../wip/libXrender/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
