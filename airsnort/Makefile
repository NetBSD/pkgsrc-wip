# $NetBSD: Makefile,v 1.4 2005/04/11 21:09:40 tvierling Exp $
#

DISTNAME=		airsnort-0.2.6
CATEGORIES=		wip net security linux
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=airsnort/}
PKGREVISION=		1

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://airsnort.sourceforge.net/
COMMENT=		WLAN sniffer and realtime WEP cracker

DEPENDS+=		linux-wlan-ng>=0.2:../../wip/linux-wlan-ng/

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Linux-*-*

SUBST_CLASSES=sbin

SUBST_FILES.sbin=${WRKSRC}/src/PacketSource.c
SUBST_STAGE.sbin=post-extract
SUBST_SED.sbin=-e 's,/sbin/wl,${PREFIX}/sbin/wl,g'

.include "../../x11/gtk2/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
