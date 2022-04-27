# $NetBSD: buildlink3.mk,v 1.25 2013/12/04 14:14:33 obache Exp $

BUILDLINK_TREE+=	apache-arrow

.if !defined(APACHE_ARROW_BUILDLINK3_MK)
APACHE_ARROW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.apache-arrow+=	apache-arrow>=7.0.0
BUILDLINK_ABI_DEPENDS.apache-arrow+=	apache-arrow>=7.0.0
BUILDLINK_PKGSRCDIR.apache-arrow?=	../../wip/apache-arrow
.endif # APACHE_ARROW_BUILDLINK3_MK

BUILDLINK_TREE+=	-apache-arrow
