# $NetBSD$

BUILDLINK_TREE+=	tg_owt

.if !defined(TG_OWT_BUILDLINK3_MK)
TG_OWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tg_owt+=	tg_owt>=git
BUILDLINK_PKGSRCDIR.tg_owt?=	../../wip/tg_owt-git

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../audio/libopus/buildlink3.mk"
#.include "../../comms/srtp/buildlink3.mk"
#.include "../../devel/libevent/buildlink3.mk"
#.include "../../devel/protobuf/buildlink3.mk"
#.include "../../graphics/jpeg/buildlink3.mk"
#.include "../../multimedia/ffmpeg4/buildlink3.mk"
#.include "../../multimedia/libvpx/buildlink3.mk"
#.include "../../wip/openh264/buildlink3.mk"
#.include "../../wip/usrsctp/buildlink3.mk"
.endif	# TG_OWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tg_owt
