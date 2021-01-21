# $NetBSD$

BUILDLINK_TREE+=	go-rice

.if !defined(GO_RICE_BUILDLINK3_MK)
GO_RICE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-rice=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-rice?=		build

BUILDLINK_API_DEPENDS.go-rice+=	go-rice>=1.0.2
BUILDLINK_PKGSRCDIR.go-rice?=	../../wip/go-rice

.include "../../devel/go-spew/buildlink3.mk"
.include "../../wip/go-fastprinter/buildlink3.mk"
.include "../../wip/go-fasttemplate/buildlink3.mk"
.include "../../wip/go-flags/buildlink3.mk"
.include "../../wip/go-incremental/buildlink3.mk"
.include "../../wip/go-rsrc/buildlink3.mk"
.include "../../wip/go-streamquote/buildlink3.mk"
.include "../../wip/go-zipexe/buildlink3.mk"
.endif	# GO_RICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-rice
