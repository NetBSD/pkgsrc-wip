# $NetBSD$

BUILDLINK_TREE+=	go-python

.if !defined(GO_PYTHON_BUILDLINK3_MK)
GO_PYTHON_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-python=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-python?=		build

BUILDLINK_API_DEPENDS.go-python+=	go-python>=0.1.0
BUILDLINK_PKGSRCDIR.go-python?=	../../wip/go-python
.endif	# GO_PYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-python
