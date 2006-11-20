# $NetBSD: Makefile,v 1.3 2006/11/20 17:54:25 kh-p Exp $

DISTNAME=		mcabber-0.8.3
CATEGORIES=		chat
MASTER_SITES=		http://www.lilotux.net/~mikael/mcabber/files/
EXTRACT_SUFX=		.tar.bz2


MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://www.lilotux.net/~mikael/mcabber/
COMMENT=		Jabber console client

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake xgettext
USE_NCURSES=		yes

#Work in Progress for UTF-8 issue.
#CONFIGURE_ENV+= CFLAGS=${CFLAGS:M*:Q} CPPFLAGS=${CPPFLAGS:M*:Q}
#CFLAGS+=        -I${LOCALBASE}/include
#CPPFLAGS=       ${CFLAGS}
#LDFLAGS+=       -lcrypto -L${LOCALBASE}/lib

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
