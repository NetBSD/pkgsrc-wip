# $NetBSD: Makefile,v 1.8 2004/05/04 09:36:10 moubctez Exp $
#

DISTNAME=	gg2-2.0.2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ggadu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://ggadu.sourceforge.net/
COMMENT=	Instant messenger software for Poland; Jabber plugin included

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
PKGCONFIG_OVERRIDE+=	${WRKSRC}/lib/gg2_core.pc.in
GNU_CONFIGURE=		yes
LIBS+=			-lm

CONFIGURE_ARGS+=	--with-gui --with-gadu --with-tlen \
			--with-sms --with-xosd --with-oss

.include "../../chat/ekg/buildlink3.mk"
.include "../../chat/libtlen/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/xosd/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
