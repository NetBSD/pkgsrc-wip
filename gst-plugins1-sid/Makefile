# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-sid/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Commodore 64 audio plugin

GST_PLUGINS+=	sidplay

.include "../../wip/gst-plugins1-ugly/Makefile.common"
.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
