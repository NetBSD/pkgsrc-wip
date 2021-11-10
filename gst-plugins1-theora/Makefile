# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-theora/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - Theora video plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	theora

.include "../../wip/gst-plugins1-base/Makefile.common"
.include "../../wip/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
