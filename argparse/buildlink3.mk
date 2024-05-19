# $NetBSD$

BUILDLINK_TREE+=	argparse

.if !defined(ARGPARSE_BUILDLINK3_MK)
ARGPARSE_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.argparse?=	build

BUILDLINK_API_DEPENDS.argparse+=	argparse>=3.0
BUILDLINK_PKGSRCDIR.argparse?=		../../wip/argparse
.endif	# ARGPARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-argparse
