# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:17:46 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBINSTALLER_BUILDLINK3_MK:=	${LIBINSTALLER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libinstaller
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibinstaller}
BUILDLINK_PACKAGES+=	libinstaller

.if !empty(LIBINSTALLER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libinstaller+=	libinstaller>=5.1
BUILDLINK_PKGSRCDIR.libinstaller?=	../../wip/libinstaller
.endif	# LIBINSTALLER_BUILDLINK3_MK

.include "../../wip/libaura/buildlink3.mk"
.include "../../wip/libdfui/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
