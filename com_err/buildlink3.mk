# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:47:32 cheusov Exp $

BUILDLINK_TREE+=	com_err

.if !defined(COM_ERR_BUILDLINK3_MK)
COM_ERR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.com_err+=	com_err>=1.35
BUILDLINK_PKGSRCDIR.com_err?=	../../wip/com_err

BUILDLINK_FILES.com_err+=	share/et/*
BUILDLINK_PASSTHRU_DIRS=	${LOCALBASE}/share/et
.endif # COM_ERR_BUILDLINK3_MK

BUILDLINK_TREE+=	-com_err
