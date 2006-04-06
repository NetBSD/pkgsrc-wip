# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:17:20 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GETTEXT_BUILDLINK3_MK:=	${GETTEXT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gettext
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngettext}
BUILDLINK_PACKAGES+=	gettext

.if !empty(GETTEXT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.10.35nb1
BUILDLINK_ABI_DEPENDS.gettext+=	gettext-lib>=0.14.1
BUILDLINK_PKGSRCDIR.gettext?=	../../wip/gettext-lib
.endif	# GETTEXT_BUILDLINK3_MK

# libiconv/buildlink3.mk is included by gettext-lib/builtin.mk
#.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_LDFLAGS.gettext+=	-lintl

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
