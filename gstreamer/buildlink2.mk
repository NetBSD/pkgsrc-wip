# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/15 18:02:12 bmeurer Exp $
#
# This Makefile fragment is included by packages that use gstreamer.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(GSTREAMER_BUILDLINK2_MK)
GSTREAMER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gstreamer
BUILDLINK_DEPENDS.gstreamer?=		gstreamer>=0.6.0
BUILDLINK_PKGSRCDIR.gstreamer?=		../../wip/gstreamer

EVAL_PREFIX+=	BUILDLINK_PREFIX.gstreamer=gstreamer
BUILDLINK_PREFIX.gstreamer_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gst.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstatomic.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstconfig.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstobject.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gsttypes.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstautoplug.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstbin.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstbuffer.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstbufferpool-default.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstcaps.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstclock.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstcompat.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstcpu.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstdata.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstelement.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstevent.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstextratypes.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstformat.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstindex.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstinfo.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstlog.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstmacros.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstmemchunk.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstpad.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstpipeline.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstplugin.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstpluginfeature.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstprobe.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstprops.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstqueue.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstquery.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstscheduler.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstsystemclock.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstthread.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gsttrace.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gsttrashstack.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gsttype.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gsttypefind.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gsturi.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstutils.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstregistry.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstparse.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstxml.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstversion.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstmarshal.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/gstenumtypes.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/bytestream/bytestream.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/control/control.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/control/dparammanager.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/control/dparam.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/control/dparam_smooth.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/control/unitconvert.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/control/dparamcommon.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/control/dplinearinterp.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/getbits/getbits.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/putbits/putbits.h
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstautoplugcache.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstautoplugger.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstbasicomegascheduler.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstbasicwingoscheduler.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstbytestream.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstelements.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstgetbits.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstindexers.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstoptomegascheduler.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstoptscheduler.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstoptwingoscheduler.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstputbits.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstspider.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgststaticautoplug.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgststaticautoplugrender.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgsttypes.*
BUILDLINK_FILES.gstreamer+=	lib/libgstcontrol-0.6.*
BUILDLINK_FILES.gstreamer+=	lib/libgstreamer-0.6.*
BUILDLINK_FILES.gstreamer+=	lib/pkgconfig/gstreamer-0.6.pc
BUILDLINK_FILES.gstreamer+=	lib/pkgconfig/gstreamer-control-0.6.pc

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../lang/python22/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

BUILDLINK_TARGETS+=	gstreamer-buildlink

gstreamer-buildlink: _BUILDLINK_USE

.endif	# GSTREAMER_BUILDLINK2_MK
