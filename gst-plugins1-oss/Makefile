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
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	sys/oss/*
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.endif

.include "../../wip/gst-plugins1-good/Makefile.common"
.include "../../mk/bsd.pkg.mk"
