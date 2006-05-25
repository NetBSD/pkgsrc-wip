# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/05/25 01:40:42 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXVMC_BUILDLINK3_MK:=	${LIBXVMC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXvMC
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXvMC}
BUILDLINK_PACKAGES+=	libXvMC

.if !empty(LIBXVMC_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libXvMC+=	libXvMC>=1.0.2
BUILDLINK_PKGSRCDIR.libXvMC?=	../../new/libXvMC
.endif	# LIBXVMC_BUILDLINK3_MK

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXv/buildlink3.mk"
#.include "../../wip/videoproto/buildlink3.mk"
#.include "../../x11/xextproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
