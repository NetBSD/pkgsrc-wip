# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-vpx/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - VP8/VP9 plugin

GST_PLUGINS+=	vpx

.include "../../wip/gst-plugins1-good/Makefile.common"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
