# $NetBSD: buildlink3.mk,v 1.3 2008/01/18 04:30:15 tnn2 Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
KDEPIMLIBS_BUILDLINK3_MK:=	${KDEPIMLIBS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	kdepimlibs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdepimlibs}
BUILDLINK_PACKAGES+=	kdepimlibs
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}kdepimlibs

.if ${KDEPIMLIBS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.kdepimlibs+=	kdepimlibs4>=4.0.0
BUILDLINK_ABI_DEPENDS.kdepimlibs?=	kdepimlibs4>=4.0.0nb1
BUILDLINK_PKGSRCDIR.kdepimlibs?=	../../wip/kdepimlibs4
.endif	# KDEPIMLIBS_BUILDLINK3_MK

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
