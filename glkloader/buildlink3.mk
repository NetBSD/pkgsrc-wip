# $NetBSD: buildlink3.mk,v 1.2 2005/03/03 14:02:28 dillo Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLKLOADER_BUILDLINK3_MK:=	${GLKLOADER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	glkloader
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nglkloader}
BUILDLINK_PACKAGES+=	glkloader

.if !empty(GLKLOADER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.glkloader+=	glkloader>=0.3.2
BUILDLINK_PKGSRCDIR.glkloader?=	../../wip/glkloader

BUILDLINK_TRANSFORM+=	l:glk:glkloader
BUILDLINK_TARGETS+=	buildlink-glkloader-hook

buildlink-glkloader-hook:
	${LN} -s glkloader ${BUILDLINK_DIR}/include/glk
	${LN} -s Make.glkloader ${BUILDLINK_DIR}/include/glk/Make.glk
.endif	# GLKLOADER_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
