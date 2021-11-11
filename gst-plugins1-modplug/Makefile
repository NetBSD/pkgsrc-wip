# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-modplug/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MOD/S3M/XM/IT decoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	modplug

.include "../../wip/gst-plugins1-bad/Makefile.common"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
