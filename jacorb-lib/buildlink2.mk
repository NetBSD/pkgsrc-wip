# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/11/29 17:57:27 daprice Exp $
#
# This Makefile fragment is included by packages that use JacORB-lib.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(JACORB_LIB_BUILDLINK2_MK)
JACORB_LIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			JacORB-lib
BUILDLINK_DEPENDS.JacORB-lib?=		JacORB-lib>=1_4_1
BUILDLINK_PKGSRCDIR.JacORB-lib?=		../../corba/jacorb-lib

EVAL_PREFIX+=	BUILDLINK_PREFIX.JacORB-lib=JacORB-lib
BUILDLINK_PREFIX.JacORB-lib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.JacORB-lib+=	lib/java/IDL.jar
BUILDLINK_FILES.JacORB-lib+=	lib/java/JacORB.jar

.include "../../lang/sun-jdk13/buildlink2.mk"

BUILDLINK_TARGETS+=	JacORB-lib-buildlink

JacORB-lib-buildlink: _BUILDLINK_USE

.endif	# JACORB_LIB_BUILDLINK2_MK
