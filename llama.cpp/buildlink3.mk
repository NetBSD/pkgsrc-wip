# $NetBSD$

BUILDLINK_TREE+=	llama.cpp

.if !defined(LLAMA.CPP_BUILDLINK3_MK)
LLAMA.CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.llama.cpp+=	llama.cpp>=0.0.2.4233
BUILDLINK_PKGSRCDIR.llama.cpp?=		../../wip/llama.cpp
.endif	# LLAMA.CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-llama.cpp
