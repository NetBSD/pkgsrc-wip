# $NetBSD: gd.mk,v 1.1.1.1 2004/06/09 23:21:59 xtraeme Exp $
#
# Makefile fragment to choose the correct gd package.
#

.if !defined(GD_MK)
GD_MK=		1

.include "../../mk/bsd.prefs.mk"

GD_NOX11_INSTALLED!=	\
	if ${PKG_INFO} -qe gd-nox11; then	\
		${ECHO} "yes";			\
	else					\
		${ECHO} "no";			\
	fi

.if ${GD_NOX11_INSTALLED} == "yes"
.  include "../../wip/gd-nox11/buildlink3.mk"
.else
.  include "../../wip/gd/buildlink3.mk"
.endif

.endif # GD_MK
