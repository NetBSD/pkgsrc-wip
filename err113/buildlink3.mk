# $NetBSD$

BUILDLINK_TREE+=	err113

.if !defined(ERR113_BUILDLINK3_MK)
ERR113_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.err113=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.err113?=		build

BUILDLINK_API_DEPENDS.err113+=	err113>=20210110
BUILDLINK_PKGSRCDIR.err113?=	../../wip/err113

.include "../../devel/go-mod/buildlink3.mk"
.include "../../devel/go-tools/buildlink3.mk"
.include "../../devel/go-xerrors/buildlink3.mk"
.endif	# ERR113_BUILDLINK3_MK

BUILDLINK_TREE+=	-err113
