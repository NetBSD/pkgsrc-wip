# $NetBSD: Makefile,v 1.8 2003/09/25 18:56:11 marc Exp $

.include "../xfce4/Makefile.common"

PKGNAME=	xfce4-fm-${XFCE4_VERSION}
DISTNAME=	xffm-${XFCE4_VERSION}
CATEGORIES=	sysutils
COMMENT=	XFce4 filemanager

MESSAGE_SRC+=	${.CURDIR}/MESSAGE

PKGCONFIG_OVERRIDE=	src/xffm-1.0.pc.in

.include "../../databases/dbh/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
