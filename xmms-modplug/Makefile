# $NetBSD: Makefile,v 1.4 2003/12/22 03:29:44 bencollver Exp $
#

DISTNAME=		modplugxmms-2.05
PKGNAME=		xmms-modplug-2.05
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=modplug-xmms/}

MAINTAINER=		ben@netbsd.org
HOMEPAGE=		http://modplug-xmms.sourceforge.net/
COMMENT=		XMMS plugin based on modplug

DEPENDS+=		unzip-[0-9]*:../../archivers/unzip

LDFLAGS+=		-lm -lossaudio
USE_X11=		yes
USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool-disable-static

CFLAGS+=		-DDEVICE_NAME="\"\\\"${DEVOSSSOUND}\\\"\""

.include "../../wip/libmodplug/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
