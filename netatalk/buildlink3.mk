# $NetBSD: buildlink3.mk,v 1.1 2013/06/07 00:28:23 makoto Exp $

BUILDLINK_TREE+=	netatalk

.if !defined(NETATALK_BUILDLINK3_MK)
NETATALK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netatalk+=	netatalk>=2.0.3nb2
BUILDLINK_ABI_DEPENDS.netatalk+=	netatalk>=2.0.3nb3
BUILDLINK_PKGSRCDIR.netatalk?=		../../net/netatalk
BUILDLINK_DEPMETHOD.netatalk?=		build
.endif # NETATALK_BUILDLINK3_MK

BUILDLINK_TREE+=	-netatalk
