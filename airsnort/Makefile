# $NetBSD: Makefile,v 1.1.1.1 2004/11/27 23:42:45 poppnk Exp $
#

DISTNAME=		airsnort-0.2.6
CATEGORIES=		wip net security linux
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=airsnort/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://airsnort.sourceforge.net/
COMMENT=		WLAN sniffer and realtime WEP cracker

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../x11/gtk2/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
