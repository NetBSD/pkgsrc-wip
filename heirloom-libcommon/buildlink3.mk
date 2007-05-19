# $NetBSD: buildlink3.mk,v 1.1 2007/05/19 13:26:16 cheusov Exp $
BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
HEIRLOOM_LIBCOMMON_BUILDLINK3_MK:=	${HEIRLOOM_LIBCOMMON_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	heirloom-libcommon
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nheirloom-libcommon}
BUILDLINK_PACKAGES+=	heirloom-libcommon
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}heirloom-libcommon

.if ${HEIRLOOM_LIBCOMMON_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.heirloom-libcommon+=	heirloom-libcommon>=070227
BUILDLINK_PKGSRCDIR.heirloom-libcommon?=	../../wip/heirloom-libcommon
BUILDLINK_DEPMETHOD.heirloom-libcommon?=	build
BUILDLINK_INCDIRS.heirloom-libcommon+=		include/heirloom
.endif	# HEIRLOOM_LIBCOMMON_BUILDLINK3_MK

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
