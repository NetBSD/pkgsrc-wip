# $NetBSD: buildlink3.mk,v 1.3 2004/03/10 05:46:30 jeremy-c-reed Exp $
#
# This file was created automatically using createbuildlink-3.2.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GETTEXT_RUNTIME_BUILDLINK3_MK:=	${GETTEXT_RUNTIME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gettext-runtime
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngettext-runtime}
BUILDLINK_PACKAGES+=	gettext-runtime

.if !empty(GETTEXT_RUNTIME_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gettext-runtime+=	gettext-runtime>=0.14.1
BUILDLINK_PKGSRCDIR.gettext-runtime?=	../../wip/gettext-runtime

# XXX need to only depend on GNU libiconv on non-glibc systems
.include "../../converters/libiconv/buildlink3.mk"

.endif	# GETTEXT_RUNTIME_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
