# $NetBSD: Makefile,v 1.1.1.1 2003/11/29 21:18:42 mpasternak Exp $
#

DISTNAME=		gg2-2.0pre3
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggadu/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://ggadu.sourceforge.net/
COMMENT=		Instant messenger software for Poland; Jabber plugin included

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/lib/gg2_core.pc.in
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-gui --with-gadu --with-tlen --with-jabber \
			--with-sms --with-osd --with-docklet --with-oss

.include "../../wip/libtlen/buildlink2.mk"
.include "../../chat/ekg/buildlink2.mk"
.include "../../x11/xosd/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
