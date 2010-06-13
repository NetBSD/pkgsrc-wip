# $NetBSD: buildlink3.mk,v 1.2 2010/06/13 22:46:58 thomasklausner Exp $

BUILDLINK_TREE+=	couchdb-glib

.if !defined(COUCHDB_GLIB_BUILDLINK3_MK)
COUCHDB_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.couchdb-glib+=	couchdb-glib>=0.5.3
BUILDLINK_ABI_DEPENDS.couchdb-glib?=	couchdb-glib>=0.5.99nb1
BUILDLINK_PKGSRCDIR.couchdb-glib?=	../../wip/couchdb-glib


.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../wip/libuuid/buildlink3.mk"
.endif	# COUCHDB_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-couchdb-glib
