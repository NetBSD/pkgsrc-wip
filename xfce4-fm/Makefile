# $NetBSD: Makefile,v 1.6 2003/07/04 11:13:52 marttikuparinen Exp $

.include "../xfce4/Makefile.common"

XFCE4_VERSION=	3.91.410

PKGNAME=	xfce4-fm-${XFCE4_VERSION}
DISTNAME=	xffm-${XFCE4_VERSION}
CATEGORIES=	sysutils
COMMENT=	XFce4 filemanager

MESSAGE_SRC+=	${.CURDIR}/MESSAGE

.include "../../databases/dbh/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
