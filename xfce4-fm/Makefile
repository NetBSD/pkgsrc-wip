# $NetBSD: Makefile,v 1.1.1.1 2003/06/04 07:37:26 marttikuparinen Exp $

.include "../xfce4/Makefile.common"

PKGNAME=	xfce4-fm-${XFCE4_VERSION}
COMMENT=	XFce4 filemanager

WRKSRC=		${WRKDIR}/xfce-devel/xffm

.include "../../databases/dbh/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
