# $NetBSD: Makefile,v 1.5 2004/02/19 18:08:38 thomasklausner Exp $
#

DISTNAME=	gg2-2.0pre6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ggadu/}

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://ggadu.sourceforge.net/
COMMENT=	Instant messenger software for Poland; Jabber plugin included

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/lib/gg2_core.pc.in
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-gui --with-gadu --with-tlen \
			--with-sms --with-xosd --with-oss

.include "../../wip/libtlen/buildlink3.mk"
.include "../../chat/ekg/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/xosd/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
