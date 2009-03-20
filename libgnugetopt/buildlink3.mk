# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:48 jsonn Exp $

BUILDLINK_TREE+=	libgnugetopt

.if !defined(LIBGNUGETOPT_BUILDLINK3_MK)
LIBGNUGETOPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnugetopt+=	libgnugetopt>=1.2
BUILDLINK_PKGSRCDIR.libgnugetopt?=	../../wip/libgnugetopt
.endif # LIBGNUGETOPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnugetopt
