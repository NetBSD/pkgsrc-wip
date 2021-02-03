# $NetBSD$

BUILDLINK_TREE+=	go-libudev

.if !defined(GO_LIBUDEV_BUILDLINK3_MK)
GO_LIBUDEV_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-libudev=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-libudev?=	build

BUILDLINK_API_DEPENDS.go-libudev+=	go-libudev>=0.2.1
BUILDLINK_PKGSRCDIR.go-libudev?=	../../wip/go-libudev
.endif	# GO_LIBUDEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-libudev
