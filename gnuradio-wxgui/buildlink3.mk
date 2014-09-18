# $NetBSD: buildlink3.mk,v 1.1 2014/09/18 00:43:33 makoto Exp $

BUILDLINK_TREE+=	gnuradio-wxgui

.if !defined(GNURADIO_WXGUI_BUILDLINK3_MK)
GNURADIO_WXGUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-wxgui+=	gnuradio-wxgui>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-wxgui+=	gnuradio-wxgui>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-wxgui?=	../../wip/gnuradio-wxgui
BUILDLINK_CPPFLAGS.gnuradio-wxgui+=    -I${BUILDLINK_PREFIX.gnuradio-wxgui}/include/gnuradio
.endif # GNURADIO_WXGUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-wxgui
