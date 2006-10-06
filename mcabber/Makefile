# $NetBSD: Makefile,v 1.2 2006/10/06 18:56:30 kh-p Exp $

DISTNAME=		mcabber-0.8.2
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
