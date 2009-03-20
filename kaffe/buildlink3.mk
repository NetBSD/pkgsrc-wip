# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:43 jsonn Exp $

BUILDLINK_TREE+=	kaffe

BUILDLINK_API_DEPENDS.kaffe+=	kaffe>=1.1.4nb2
BUILDLINK_ABI_DEPENDS.kaffe+=	kaffe>=1.1.4nb4
BUILDLINK_PKGSRCDIR.kaffe?=	../../wip/kaffe
BUILDLINK_JAVA_PREFIX.kaffe=	${PREFIX}/java/kaffe

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_JAVA_PREFIX.kaffe}

BUILDLINK_CPPFLAGS.kaffe= \
	-I${BUILDLINK_JAVA_PREFIX.kaffe}/include			\
	-I${BUILDLINK_JAVA_PREFIX.kaffe}/include/kaffe
.endif # KAFFE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kaffe
