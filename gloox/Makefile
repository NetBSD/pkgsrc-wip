# $NetBSD: Makefile,v 1.6 2012/09/29 00:50:35 asau Exp $

DISTNAME=		gloox-1.0
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		http://camaya.net/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://camaya.net/gloox/
COMMENT=		Jabber/XMPP client library
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

USE_LANGUAGES+=		c++ c
USE_TOOLS+=		autoconf automake
USE_LIBTOOL=		yes

.include "options.mk"

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
