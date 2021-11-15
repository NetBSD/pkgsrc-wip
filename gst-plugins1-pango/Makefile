# $NetBSD: Makefile,v 1.25 2020/08/17 20:18:25 leot Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-pango/}
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - pango plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	pango

.include "../../wip/gst-plugins1-base/Makefile.common"
.include "../../wip/gst-plugins1-base/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
