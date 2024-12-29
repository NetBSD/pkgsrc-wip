# $NetBSD$

BUILDLINK_TREE+=	dash-el

.if !defined(DASH_EL_BUILDLINK3_MK)
DASH_EL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dash-el+=	dash-el-[0-9]*
BUILDLINK_PKGSRCDIR.dash-el?=	../../wip/dash-el

BUILDLINK_CONTENTS_FILTER.dash-el+=	${EGREP} '.*\.el$$|.*\.elc$$'

.endif

BUILDLINK_TREE+=	-dash-el
