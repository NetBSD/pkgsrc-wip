# $NetBSD: buildlink3.mk,v 1.1 2011/04/18 13:22:10 genolopolis Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.kyotocabinet?=	build

BUILDLINK_TREE+=	kyotocabinet

.if !defined(KYOTOCABINET_BUILDLINK3_MK)
KYOTOCABINET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kyotocabinet+=	kyotocabinet>=1.2.51
BUILDLINK_PKGSRCDIR.kyotocabinet?=	../../wip/kyotocabinet
.endif	# KYOTOCABINET_BUILDLINK3_MK

BUILDLINK_TREE+=	-kyotocabinet
