# $NetBSD: Makefile,v 1.4 2003/06/29 10:26:31 marttikuparinen Exp $

.include "../xfce4/Makefile.common"

XFCE4_VERSION=	3.91.410

PKGNAME=	xfce4-fm-${XFCE4_VERSION}
DISTNAME=	xffm-${XFCE4_VERSION}
COMMENT=	XFce4 filemanager

.if defined(XFCE4_USE_SAMBA) && ${XFCE4_USE_SAMBA} == "YES"
.include "../../net/samba/buildlink2.mk"
.endif

.include "../../databases/dbh/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
