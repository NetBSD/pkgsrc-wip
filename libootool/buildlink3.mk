# $NetBSD: buildlink3.mk,v 1.3 2006/04/06 07:16:57 jeremy-c-reed Exp $


.include "../../wip/valknut/Makefile.version"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBOOTOOL_BUILDLINK3_MK:=	${LIBOOTOOL_BUILDLINK3_MK}+

# broken, but we can still pull in the other dependencies for dclib
.if 0 #XXX
.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libootool
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibootool}
BUILDLINK_PACKAGES+=	libootool

.if !empty(LIBOOTOOL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libootool+=	libootool>=${VALKNUT_PKG_VERSION}
BUILDLINK_PKGSRCDIR.libootool?=	../../wip/libootool
.endif	# LIBOOTOOL_BUILDLINK3_MK

.endif  # XXX

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
