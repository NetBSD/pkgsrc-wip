# $NetBSD$

BUILDLINK_TREE+=	docopt.cpp

.if !defined(DOCOPT.CPP_BUILDLINK3_MK)
DOCOPT.CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.docopt.cpp+=	docopt.cpp>=0.6.3
BUILDLINK_PKGSRCDIR.docopt.cpp?=	../../wip/docopt.cpp
.endif	# DOCOPT.CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-docopt.cpp
