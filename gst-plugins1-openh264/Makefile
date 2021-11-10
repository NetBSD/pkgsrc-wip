# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-openh264/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - H.264/MPEG-4 decoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	openh264

.include "../../wip/gst-plugins1-bad/Makefile.common"
.include "../../wip/openh264/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
