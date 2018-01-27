# $NetBSD: Makefile,v 1.4 2015/08/29 16:11:03 f8l Exp $
.include "../../wip/dwb-gtk2/Makefile.common"

PKGNAME=	${DISTNAME:S/dwb/dwb-gtk3/}
PKGREVISION=	1
COMMENT=	Dynamic WebKit browser, gtk3 version

MAKE_ENV+=	GTK=3

.include "../../www/webkit24-gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
