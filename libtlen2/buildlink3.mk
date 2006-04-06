# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:17:56 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBTLEN2_BUILDLINK3_MK:=	${LIBTLEN2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libtlen2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibtlen2}
BUILDLINK_PACKAGES+=	libtlen2

.if !empty(LIBTLEN2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libtlen2+=	libtlen2>=20040301
BUILDLINK_PKGSRCDIR.libtlen2?=	../../wip/libtlen2

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.endif	# LIBTLEN2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
