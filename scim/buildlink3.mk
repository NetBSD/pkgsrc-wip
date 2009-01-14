# $NetBSD: buildlink3.mk,v 1.6 2009/01/14 13:55:00 obache Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SCIM_BUILDLINK3_MK:=	${SCIM_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	scim
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nscim}
BUILDLINK_PACKAGES+=	scim
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}scim

.if ${SCIM_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.scim+=	scim>=1.4.7
BUILDLINK_PKGSRCDIR.scim?=	../../wip/scim

PRINT_PLIST_AWK+=	/^@dirrm lib\/scim-1.0\/1.4.0$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/scim-1.0$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/scim-1.0\/1.4.0\/(SetupUI|IMEngine|Helper|FrontEnd|Filter|Config)$$/ \
				{print "@comment in scim: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/scim$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/scim\/icons$$/ \
				{print "@comment in scim: " $$0; next; }
.endif	# SCIM_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
