# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-faac/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - AAC encoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	faac

.include "../../wip/gst-plugins1-bad/Makefile.common"
.include "../../audio/faac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
