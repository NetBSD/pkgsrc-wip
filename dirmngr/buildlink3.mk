# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/10/15 11:54:28 johnrshannon Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
DIRMNGR_BUILDLINK3_MK:=	${DIRMNGR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	dirmngr
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndirmngr}
BUILDLINK_PACKAGES+=	dirmngr

.if !empty(DIRMNGR_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.dirmngr+=	dirmngr>=0.5.6
BUILDLINK_PKGSRCDIR.dirmngr?=	../../wip/dirmngr
.endif	# DIRMNGR_BUILDLINK3_MK

.include "../../wip/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../wip/libassuan/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
