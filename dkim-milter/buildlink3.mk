# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:40 jsonn Exp $

BUILDLINK_TREE+=	dkim-milter

.if !defined(DKIM_MILTER_BUILDLINK3_MK)
DKIM_MILTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dkim-milter+=	dkim-milter>=2.7.2
BUILDLINK_PKGSRCDIR.dkim-milter?=	../../wip/dkim-milter
BUILDLINK_DEPMETHOD.dkim-milter?=	build

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.endif # DKIM_MILTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-dkim-milter
