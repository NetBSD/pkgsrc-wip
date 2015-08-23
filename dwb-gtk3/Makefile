# $NetBSD: Makefile,v 1.3 2015/08/23 01:08:59 leot1990 Exp $
.include "../../wip/dwb-gtk3/Makefile.common"

PKGNAME=        ${DISTNAME:S/dwb/dwb-gtk3/}
PKGREVISION=	1
COMMENT=	Dynamic WebKit browser, gtk3 version

MAKE_ENV+=	GTK=3

.include "../../www/webkit24-gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
