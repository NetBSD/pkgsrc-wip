# $NetBSD: Makefile,v 1.3 2015/09/03 10:08:53 f8l Exp $
.include "../../wip/dwb-gtk2-git/Makefile.common"

PKGNAME=	${DISTNAME:S/dwb/dwb-gtk3/}
COMMENT=	Dynamic WebKit browser, gtk3 version

MAKE_ENV+=	GTK=3

.include "../../www/webkit24-gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
