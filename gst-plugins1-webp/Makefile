# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-webp/}
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - WebP image plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	webp

.include "../../wip/gst-plugins1-bad/Makefile.common"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
