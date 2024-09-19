# $NetBSD: buildlink3.mk,v 1.1 2012/10/02 21:46:53 othyro Exp $

BUILDLINK_TREE+=	rubrica2

.if !defined(RUBRICA2_BUILDLINK3_MK)
RUBRICA2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rubrica2+=	rubrica2>=2.0.10
BUILDLINK_PKGSRCDIR.rubrica2?=		../../wip/rubrica2

.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# RUBRICA2_BUILDLINK3_MK

BUILDLINK_TREE+=	-rubrica2
