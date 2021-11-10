# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-jack/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - JACK plugin

GST_PLUGINS+=	jack

.include "../../wip/gst-plugins1-good/Makefile.common"
.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
