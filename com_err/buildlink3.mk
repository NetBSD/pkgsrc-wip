# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:40 jsonn Exp $

BUILDLINK_TREE+=	com_err

BUILDLINK_API_DEPENDS.com_err+=	com_err>=1.35
BUILDLINK_PKGSRCDIR.com_err?=	../../wip/com_err

BUILDLINK_FILES.com_err+=	share/et/*
BUILDLINK_PASSTHRU_DIRS=	${LOCALBASE}/share/et
.endif # COM_ERR_BUILDLINK3_MK

BUILDLINK_TREE+=	-com_err
