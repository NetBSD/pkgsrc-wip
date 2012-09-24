# $NetBSD: Makefile,v 1.10 2012/09/24 16:56:32 asau Exp $
#

DISTNAME=		airsnort-0.2.7e
PKGREVISION=		1
CATEGORIES=		net security linux
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=airsnort/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://airsnort.shmoo.com/
COMMENT=		WLAN sniffer and realtime WEP cracker
LICENSE=		gnu-gpl-v2

DEPENDS+=		linux-wlan-ng>=0.2:../../wip/linux-wlan-ng

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Linux-*-*

SUBST_CLASSES+=		sbin
SUBST_FILES.sbin=	${WRKSRC}/src/PacketSource.c
SUBST_STAGE.sbin=	pre-build
SUBST_SED.sbin+=	-e 's,/sbin/wl,${PREFIX}/sbin/wl,g'

.include "../../x11/gtk2/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
