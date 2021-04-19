# $NetBSD: readline.buildlink3.mk,v 1.6 2019/09/02 02:23:02 rillig Exp $
#
# This Makefile fragment can be used to check for builtin libseccomp
# on Linux

LIBSECCOMP_BUILDLINK3_MK:=	${LIBSECCOMP_BUILDLINK3_MK}+
.include "../../mk/bsd.fast.prefs.mk"

.if !empty(LIBSECCOMP_BUILDLINK3_MK:M+)

CHECK_BUILTIN.libseccomp:=	yes
.include "libseccomp.builtin.mk"
CHECK_BUILTIN.libseccomp:=	no

BUILDLINK_TREE+=		libseccomp -libseccomp
BUILDLINK_BUILTIN_MK=		"../../wip/mk/libseccomp.builtin.mk"
BUILDLINK_LDADD.libseccomp=	-lseccomp

.endif	# LIBSECCOMP_BUILDLINK3_MK
