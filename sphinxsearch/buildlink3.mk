# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/01 13:37:31 fhajny Exp $

BUILDLINK_TREE+=			sphinxsearch

.if !defined(SPHINXSEARCH_BUILDLINK3_MK)
SPHINXSEARCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sphinxsearch+=	sphinxsearch>=0.9.8.1nb1
BUILDLINK_PKGSRCDIR.sphinxsearch?=	../../joyent/sphinxsearch

.endif	# SPHINXSEARCH_BUILDLINK3_MK

BUILDLINK_TREE+=			-sphinxsearch
