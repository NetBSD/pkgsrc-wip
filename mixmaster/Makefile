# $NetBSD: Makefile,v 1.1.1.1 2003/08/18 18:25:03 tvierling Exp $
#
# XXX WIP: only installs parts necessary for client operation.
# Server parts still in work (need to add informational texts into
# $PREFIX/share/examples/mixmaster that correspond with what the
# ugly interactive "Install" script does).

DISTNAME=		mixmaster-2.9.0
CATEGORIES=		wip security mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mixmaster/}

MAINTAINER=		tv@pobox.com
HOMEPAGE=		http://mixmaster.sourceforge.net/
COMMENT=		The Mixmaster anonymous remailer client

USE_BUILDLINK2=		yes

BUILD_DIRS=		${WRKSRC}/Src
MAKE_FLAGS+=		CC=${CC} CFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q} LIBS=
MAKEFILE=		Makefile.in

.include "../../mk/bsd.prefs.mk"

.if defined(USE_IDEA) && ${USE_IDEA} == YES
.include "../../security/libidea/buildlink2.mk"
CFLAGS+=		-DUSE_IDEA
LDFLAGS+=		-lidea # must go before -lcrypto to override
.endif

# note: HAVE_GETDOMAINNAME is *not* set.  Mixmaster abuses this value,
# using it as DNS (not NIS) domain name.

CFLAGS+=		-DUSE_NCURSES -DUSE_PCRE -DUSE_SOCK -DUSE_ZLIB
LDFLAGS+=		-lcrypto -lncurses -lpcre -lz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src/mix ${PREFIX}/bin/mix
	${INSTALL_DATA} ${WRKSRC}/mix.1 ${PREFIX}/man/man1/mix.1

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
