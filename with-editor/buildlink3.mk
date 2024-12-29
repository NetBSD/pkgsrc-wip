# $NetBSD$

BUILDLINK_TREE+=	with-editor

.if !defined(WITH_EDITOR_BUILDLINK3_MK)
WITH_EDITOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.with-editor+=	with-editor-[0-9]*
BUILDLINK_PKGSRCDIR.with-editor?=	../../wip/with-editor

BUILDLINK_CONTENTS_FILTER.with-editor+=	${EGREP} '.*\.el$$|.*\.elc$$'

.endif

BUILDLINK_TREE+=	-with-editor
