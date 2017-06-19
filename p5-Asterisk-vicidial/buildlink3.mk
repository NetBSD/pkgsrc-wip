# $NetBSD$

BUILDLINK_TREE+=	p5-Asterisk-vicidial

.if !defined(P5_ASTERISK_VICIDIAL_BUILDLINK3_MK)
P5_ASTERISK_VICIDIAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-Asterisk-vicidial+=	p5-Asterisk-vicidial>=0.08
BUILDLINK_ABI_DEPENDS.p5-Asterisk-vicidial?=	p5-Asterisk-vicidial>=0.08
BUILDLINK_PKGSRCDIR.p5-Asterisk-vicidial?=	../../wip/p5-Asterisk-vicidial
.endif	# P5_ASTERISK_VICIDIAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-Asterisk-vicidial
