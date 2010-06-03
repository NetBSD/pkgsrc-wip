# $NetBSD: buildlink3.mk,v 1.1 2010/06/03 08:50:03 jihbed Exp $

BUILDLINK_TREE+=	repositoryhandler

.if !defined(REPOSITORYHANDLER_BUILDLINK3_MK)
REPOSITORYHANDLER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.repositoryhandler+=	repositoryhandler>=0.3
BUILDLINK_PKGSRCDIR.repositoryhandler?=	../../wip/repositoryhandler

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# REPOSITORYHANDLER_BUILDLINK3_MK

BUILDLINK_TREE+=	-repositoryhandler
