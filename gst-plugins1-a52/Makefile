# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-a52/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Dolby AC-3 audio plugin

GST_PLUGINS+=	a52

.include "../../wip/gst-plugins1-ugly/Makefile.common"
.include "../../audio/liba52/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
