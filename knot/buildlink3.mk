# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.19.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.

BUILDLINK_TREE+=	knot

.if !defined(KNOT_BUILDLINK3_MK)
KNOT_BUILDLINK3_MK:=

# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.knot?=	build

BUILDLINK_API_DEPENDS.knot+=	knot>=3.5.4
BUILDLINK_PKGSRCDIR.knot?=	../../net/knot

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../databases/lmdb/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../devel/userspace-rcu/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.endif	# KNOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-knot
