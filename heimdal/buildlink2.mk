# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/09/25 16:25:06 marmfield Exp $

.if !defined(HEIMDAL_BUILDLINK2_MK)
HEIMDAL_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# This is the ${PKGNAME} of the version of the heimdal package installed
# by pkgsrc.
#
_HEIMDAL_PKGSRC_PKGNAME=	heimdal-0.6

BUILDLINK_DEPENDS.heimdal?=	heimdal>=0.6
BUILDLINK_PKGSRCDIR.heimdal?=	../../wip/heimdal

BUILDLINK_CHECK_BUILTIN.heimdal?=	NO

_HEIMDAL_H=	/usr/include/krb5/krb5.h

.if !defined(BUILDLINK_IS_BUILTIN.heimdal)
BUILDLINK_IS_BUILTIN.heimdal=   NO
.  if exists(${_HEIMDAL_H})
BUILDLINK_IS_BUILTIN.heimdal=   YES
.  endif
.endif

_NEED_HEIMDAL=  NO

.if !empty(BUILDLINK_CHECK_BUILTIN.heimdal:M[yY][eE][sS])
_NEED_HEIMDAL=  NO
.else
.  if !empty(BUILDLINK_IS_BUILTIN.heimdal:M[nN][oO])
_NEED_HEIMDAL=  YES
.  endif
.endif

.if ${_NEED_HEIMDAL} == "YES"
BUILDLINK_PACKAGES+=			heimdal
EVAL_PREFIX+=				BUILDLINK_PREFIX.heimdal=heimdal
BUILDLINK_PREFIX.heimdal_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.heimdal=		/usr
.endif
HEIMDALBASE=		${BUILDLINK_PREFIX.heimdal}
BUILD_DEFS+=		HEIMDALBASE

BUILDLINK_FILES.heimdal=	include/gssapi/*
BUILDLINK_FILES.heimdal+=	include/kadm5/*
BUILDLINK_FILES.heimdal+=	include/krb5/*
BUILDLINK_FILES.heimdal+=	lib/libasn1.*
BUILDLINK_FILES.heimdal+=	lib/libcom_err.*
BUILDLINK_FILES.heimdal+=	lib/libgssapi.*
BUILDLINK_FILES.heimdal+=	lib/libkadm5clnt.*
BUILDLINK_FILES.heimdal+=	lib/libkadm5srv.*
BUILDLINK_FILES.heimdal+=	lib/libkafs.*
BUILDLINK_FILES.heimdal+=	lib/libkrb5.*
BUILDLINK_FILES.heimdal+=	lib/libroken.*
BUILDLINK_FILES.heimdal+=	lib/libsl.*
BUILDLINK_FILES.heimdal+=	lib/libss.*

BUILDLINK_TARGETS+=	heimdal-buildlink

heimdal-buildlink: _BUILDLINK_USE

.endif	# HEIMDAL_BUILDLINK2_MK
