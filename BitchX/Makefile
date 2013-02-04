# $NetBSD: Makefile,v 1.1 2013/02/04 03:00:47 noud4 Exp $

DISTNAME=	BitchX-1.2-final
PKGNAME=	bitchx-1.2 # XXX ${DISTNAME:S|-final||:LC}
CATEGORIES=	chat
MASTER_SITES=	http://www.bitchx.ca/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bitchx.org/
COMMENT=	IRC client based on ircII
LICENSE=	unlicense # XXX has just copyright, something half NetBSD peeps does not see as
# XXX , a BSD license
# XXX glob.c is copyright 1993 by the Regents of the University of California, with modifications
# XXX "Europa" plugin is licensed under the GPLv2

WRKSRC=			${WRKDIR}/${DISTNAME:S|-final||}

HAS_CONFIGURE=		YES # are you the first one that's complaining, GNU_CONFIGURE=		YES # XXX 
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKG_MANDIR}
CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	--with-plugins

USE_TOOLS+=		gmake
USE_LANGUAGES+=		c
USE_LANGUAGES+=		# python # XXX

SUBST_CLASSES+=		manpage
SUBST_STAGE.manpage=	post-patch
SUBST_FILES.manpage+=	doc/BitchX.1
SUBST_SED.manpage+=	-e 's,@PREFIX@,${PREFIX},g'

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/bx/help/1_General/ctcp \
			share/bx/help/1_General/dcc \
			share/bx/help/2_Queries \
			share/bx/help/3_Operators \
			share/bx/help/4_Misc/bind \
			share/bx/help/4_Misc/set \
			share/bx/help/4_Misc/window \
			share/bx/help/5_Programming/on \
			share/bx/help/6_Functions \
			share/bx/help/7_Docs \
			share/bx/help/8_Scripts \
			share/bx/script \
			share/bx/translation
INSTALLATION_DIRS+=	${PKG_MANDIR}/man1

post-build:
	cd ${WRKSRC} && ${MAKE_ENV} ${WRKSRC}/../.tools/bin/gmake install # bitch me, no shell (ASau is so okay)

# XXX rest should be pkgsrc shit. ..
do-install:
	cd ${WRKSRC} && pax -rwpam ${DESTDIR}${PREFIX}/bin/* ${PREFIX}/bin
	cd ${WRKSRC} && pax -rwpam ${DESTDIR}${PREFIX}/lib/* ${PREFIX}/lib
	cd ${WRKSRC} && pax -rwpam ${DESTDIR}${PREFIX}/share/* ${PREFIX}/share
	# bet them now thing i have a pax-complex, the meat-piles those half.

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

# remeber (to yourself): i may not say some is wrong.
