# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:31:48 wiz Exp $

BUILDLINK_TREE+=	libvterm03

.if !defined(LIBVTERM03_BUILDLINK3_MK)
LIBVTERM03_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvterm03+=	libvterm03>=0.0.0
BUILDLINK_ABI_DEPENDS.libvterm03+=	libvterm03>=0.3
BUILDLINK_PKGSRCDIR.libvterm03?=	../../wip/libvterm03
BUILDLINK_INCDIRS.libvterm03+=		include/libvterm03
BUILDLINK_LIBDIRS.libvterm03+=		lib/libvterm03

BUILDLINK_TARGETS+=	buildlink-vterm-unversioned

buildlink-vterm-unversioned:
	${LN} -s ${BUILDLINK_DIR}/lib/pkgconfig/vterm03.pc \
	    ${BUILDLINK_DIR}/lib/pkgconfig/vterm.pc

.endif	# LIBVTERM03_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvterm03
