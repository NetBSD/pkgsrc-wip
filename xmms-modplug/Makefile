# $NetBSD: Makefile,v 1.7 2004/03/05 22:17:01 bencollver Exp $
#

DISTNAME=		modplugxmms-2.05
PKGNAME=		xmms-modplug-2.05
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=modplug-xmms/}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://modplug-xmms.sourceforge.net/
COMMENT=		XMMS plugin based on modplug

DEPENDS+=		unzip-[0-9]*:../../archivers/unzip

LDFLAGS+=		-lm -lossaudio
USE_X11=		yes
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool-disable-static

CFLAGS+=		-DDEVICE_NAME="\"\\\"${DEVOSSSOUND}\\\"\""

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../wip/libmodplug/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
