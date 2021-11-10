# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-aom/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - AV1 plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	aom

.include "../../wip/gst-plugins1-bad/Makefile.common"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
