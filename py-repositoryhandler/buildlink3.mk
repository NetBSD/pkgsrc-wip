# $NetBSD: buildlink3.mk,v 1.2 2013/09/09 14:05:31 thomasklausner Exp $

BUILDLINK_TREE+=	py26-repositoryhandler

.if !defined(PY26_REPOSITORYHANDLER_BUILDLINK3_MK)
PY26_REPOSITORYHANDLER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-repositoryhandler+=	py26-repositoryhandler>=0.3
BUILDLINK_ABI_DEPENDS.py26-repositoryhandler?=	py27-repositoryhandler>=0.3
BUILDLINK_PKGSRCDIR.py26-repositoryhandler?=	../../wip/py-repositoryhandler

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# PY26_REPOSITORYHANDLER_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-repositoryhandler
