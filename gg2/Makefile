# $NetBSD: Makefile,v 1.4 2004/02/17 02:55:31 blef Exp $
#

DISTNAME=	gg2-2.0pre6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ggadu/}

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://ggadu.sourceforge.net/
COMMENT=	Instant messenger software for Poland; Jabber plugin included

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/lib/gg2_core.pc.in
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-gui --with-gadu --with-tlen \
			--with-sms --with-xosd --with-oss

.include "../../wip/libtlen/buildlink2.mk"
.include "../../chat/ekg/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/xosd/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
