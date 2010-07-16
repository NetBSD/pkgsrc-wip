# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/07/16 19:17:10 jihbed Exp $

BUILDLINK_TREE+=	py26-repositoryhandler

.if !defined(PY26_REPOSITORYHANDLER_BUILDLINK3_MK)
PY26_REPOSITORYHANDLER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-repositoryhandler+=	py26-repositoryhandler>=0.3
BUILDLINK_PKGSRCDIR.py26-repositoryhandler?=	../../wip/py-repositoryhandler

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# PY26_REPOSITORYHANDLER_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-repositoryhandler
