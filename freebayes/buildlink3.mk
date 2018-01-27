# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.freebayes?=	build

BUILDLINK_TREE+=	freebayes

.if !defined(FREEBAYES_BUILDLINK3_MK)
FREEBAYES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freebayes+=	freebayes>=65c4880d09ec21f7f2755eac9476b607011522f3
BUILDLINK_PKGSRCDIR.freebayes?=		../../wip/freebayes
.endif	# FREEBAYES_BUILDLINK3_MK

BUILDLINK_TREE+=	-freebayes
