# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-oss/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Open Sound System plugin

GST_PLUGINS+=	oss

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} == "none"
PKG_SKIP_REASON+=	"Requires an OSS implementation"
.else
LDFLAGS+=		${LIBOSSAUDIO}
.endif

.include "../../wip/gst-plugins1-good/Makefile.common"
.include "../../mk/bsd.pkg.mk"
