# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-png/}
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - PNG image plugin

GST_PLUGINS+=	png

.include "../../wip/gst-plugins1-good/Makefile.common"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
