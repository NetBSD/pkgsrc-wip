# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:43:52 jsonn Exp $

BUILDLINK_TREE+=	scim

.if !defined(SCIM_BUILDLINK3_MK)
SCIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.scim+=	scim>=1.4.7
BUILDLINK_PKGSRCDIR.scim?=	../../wip/scim

PRINT_PLIST_AWK+=	/^@dirrm lib\/scim-1.0\/1.4.0$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/scim-1.0$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/scim-1.0\/1.4.0\/(SetupUI|IMEngine|Helper|FrontEnd|Filter|Config)$$/ \
				{print "@comment in scim: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/scim$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/scim\/icons$$/ \
				{print "@comment in scim: " $$0; next; }

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # SCIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-scim
