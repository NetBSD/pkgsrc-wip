# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/29 14:41:07 mpasternak Exp $
#
# This Makefile fragment is included by packages that use glib2-devel.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(GLIB2_DEVEL_BUILDLINK2_MK)
GLIB2_DEVEL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			glib2-devel
BUILDLINK_DEPENDS.glib2-devel?=		glib2-devel>=2.3.1
BUILDLINK_PKGSRCDIR.glib2-devel?=		../../wip/glib2-devel

EVAL_PREFIX+=	BUILDLINK_PREFIX.glib2-devel=glib2-devel
BUILDLINK_PREFIX.glib2-devel_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib-object.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/galloca.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/garray.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gasyncqueue.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gbacktrace.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gcache.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gcompletion.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gconvert.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gdataset.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gdate.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gdir.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gerror.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gfileutils.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/ghash.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/ghook.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gi18n-lib.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gi18n.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/giochannel.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/glist.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gmacros.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gmain.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gmarkup.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gmem.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gmessages.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gnode.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gpattern.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gprimes.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gprintf.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gqsort.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gquark.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gqueue.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/grand.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/grel.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gscanner.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gshell.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gslist.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gspawn.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gstrfuncs.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gstring.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gthread.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gthreadpool.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gtimer.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gtree.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gtypes.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gunicode.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gutils.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/glib/gwin32.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gmodule.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gboxed.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gclosure.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/genums.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gmarshal.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gobject.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gobjectnotifyqueue.c
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gparam.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gparamspecs.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gsignal.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gsourceclosure.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gtype.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gtypemodule.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gtypeplugin.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gvalue.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gvaluearray.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gvaluecollector.h
BUILDLINK_FILES.glib2-devel+=	include/glib-2.0/gobject/gvaluetypes.h
BUILDLINK_FILES.glib2-devel+=	lib/glib-2.0/include/glibconfig.h
BUILDLINK_FILES.glib2-devel+=	lib/libglib-2.0.*
BUILDLINK_FILES.glib2-devel+=	lib/libgmodule-2.0.*
BUILDLINK_FILES.glib2-devel+=	lib/libgobject-2.0.*
BUILDLINK_FILES.glib2-devel+=	lib/libgthread-2.0.*

.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	glib2-devel-buildlink

glib2-devel-buildlink: _BUILDLINK_USE

.endif	# GLIB2_DEVEL_BUILDLINK2_MK
