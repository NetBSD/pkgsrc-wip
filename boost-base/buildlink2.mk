# $NetBSD: buildlink2.mk,v 1.2 2003/09/12 21:38:57 xtraeme Exp $
#

.if !defined(BOOST_BUILDLINK2_MK)
BOOST_BUILDLINK2_MK=  #defined

USE_GCC3=yes
PTHREAD_OPT=require

BUILDLINK_PACKAGES+=			boost-base
BUILDLINK_PKGBASE.boost-base =	boost-base
BUILDLINK_DEPENDS.boost-base?=  boost-base>=1.30.0
BUILDLINK_PKGSRCDIR.boost-base?= ../../devel/boost-base

EVAL_PREFIX+=					BUILDLINK_PREFIX.boost-base=boost-base
BUILDLINK_PREFIX.boost-base_DEFAULT=${LOCALBASE}
BUILDLINK_FILES.boost-base += 	include/boost/*
BUILDLINK_FILES.boost-base +=	bin/bjam

BUILDLINK_TARGETS+=				boost-base-buildlink

boost-base-buildlink: _BUILDLINK_USE

. include "../../mk/compiler.mk"
. include "../../mk/pthread.buildlink2.mk"

.endif # BOOST_BUILDLINK2_MK
