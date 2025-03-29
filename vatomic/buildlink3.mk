BUILDLINK_TREE+=        vatomic

.if !defined(VATOMIC_BUILDLINK3_MK)
VATOMIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vatomic+=    vatomic>=2.3.1
BUILDLINK_ABI_DEPENDS.vatomic+=    vatomic>=2.3.1
BUILDLINK_PKGSRCDIR.vatomic?=      ../../wip/vatomic

.endif # VATOMIC_BUILDLINK3_MK

BUILDLINK_TREE+=        -vatomic
