# $NetBSD: buildlink3.mk,v 1.3 2015/09/17 13:48:06 makoto Exp $

BUILDLINK_TREE+=	gnuradio-wxgui

.if !defined(GNURADIO_WXGUI_BUILDLINK3_MK)
GNURADIO_WXGUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-wxgui+=	gnuradio-wxgui>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-wxgui+=	gnuradio-wxgui>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-wxgui?=	../../wip/gnuradio-wxgui
.endif # GNURADIO_WXGUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-wxgui
