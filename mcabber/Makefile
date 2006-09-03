# $NetBSD: Makefile,v 1.1.1.1 2006/09/03 21:36:40 kh-p Exp $

DISTNAME=		mcabber-0.8.1
CATEGORIES=		chat
MASTER_SITES=		http://www.lilotux.net/~mikael/mcabber/files/
EXTRACT_SUFX=		.tar.bz2


MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://www.lilotux.net/~mikael/mcabber/
COMMENT=		Jabber console client

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_NCURSES=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
