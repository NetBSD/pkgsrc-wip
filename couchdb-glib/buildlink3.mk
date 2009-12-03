# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/12/03 20:10:22 jihbed Exp $

BUILDLINK_TREE+=	couchdb-glib

.if !defined(COUCHDB_GLIB_BUILDLINK3_MK)
COUCHDB_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.couchdb-glib+=	couchdb-glib>=0.5.3
BUILDLINK_PKGSRCDIR.couchdb-glib?=	../../wip/couchdb-glib


.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../wip/libuuid/buildlink3.mk"
.endif	# COUCHDB_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-couchdb-glib
