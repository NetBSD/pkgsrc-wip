# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/29 14:41:05 mpasternak Exp $
#
# This Makefile fragment is included by packages that use atk-devel.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(ATK_DEVEL_BUILDLINK2_MK)
ATK_DEVEL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			atk-devel
BUILDLINK_DEPENDS.atk-devel?=		atk-devel>=1.4.1
BUILDLINK_PKGSRCDIR.atk-devel?=		../../wip/atk-devel

EVAL_PREFIX+=	BUILDLINK_PREFIX.atk-devel=atk-devel
BUILDLINK_PREFIX.atk-devel_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atk-enum-types.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atk.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkaction.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkcomponent.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkdocument.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkeditabletext.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkgobjectaccessible.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkhyperlink.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkhypertext.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkimage.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atknoopobject.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atknoopobjectfactory.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkobject.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkobjectfactory.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkregistry.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkrelation.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkrelationset.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkrelationtype.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkselection.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkstate.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkstateset.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkstreamablecontent.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atktable.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atktext.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkutil.h
BUILDLINK_FILES.atk-devel+=	include/atk-1.0/atk/atkvalue.h
BUILDLINK_FILES.atk-devel+=	lib/libatk-1.0.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../wip/glib2-devel/buildlink2.mk"

BUILDLINK_TARGETS+=	atk-devel-buildlink

atk-devel-buildlink: _BUILDLINK_USE

.endif	# ATK_DEVEL_BUILDLINK2_MK
