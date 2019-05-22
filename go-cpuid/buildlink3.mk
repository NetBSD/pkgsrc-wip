# $NetBSD$

BUILDLINK_TREE+=	go-cpuid

.if !defined(GO_CPUID_BUILDLINK3_MK)
GO_CPUID_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-cpuid=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-cpuid?=		build

BUILDLINK_API_DEPENDS.go-cpuid+=	go-cpuid>=1.2.1
BUILDLINK_PKGSRCDIR.go-cpuid?=		../../wip/go-cpuid
.endif	# GO_CPUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-cpuid
