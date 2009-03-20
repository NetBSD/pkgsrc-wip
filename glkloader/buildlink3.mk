# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:41 jsonn Exp $

BUILDLINK_TREE+=	glkloader

BUILDLINK_API_DEPENDS.glkloader+=	glkloader>=0.3.2
BUILDLINK_PKGSRCDIR.glkloader?=	../../wip/glkloader

BUILDLINK_TRANSFORM+=	l:glk:glkloader
BUILDLINK_TARGETS+=	buildlink-glkloader-hook

buildlink-glkloader-hook:
	${LN} -s glkloader ${BUILDLINK_DIR}/include/glk
	${LN} -s Make.glkloader ${BUILDLINK_DIR}/include/glk/Make.glk
.endif # GLKLOADER_BUILDLINK3_MK

BUILDLINK_TREE+=	-glkloader
