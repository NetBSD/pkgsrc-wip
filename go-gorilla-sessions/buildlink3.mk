# $NetBSD$

BUILDLINK_TREE+=	go-gorilla-sessions

.if !defined(GO_GORILLA_SESSIONS_BUILDLINK3_MK)
GO_GORILLA_SESSIONS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-gorilla-sessions=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-gorilla-sessions?=	build

BUILDLINK_API_DEPENDS.go-gorilla-sessions+=	go-gorilla-sessions>=1.2.1
BUILDLINK_PKGSRCDIR.go-gorilla-sessions?=	../../wip/go-gorilla-sessions

.include "../../wip/go-gorilla-securecookie/buildlink3.mk"
.endif	# GO_GORILLA_SESSIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-gorilla-sessions
