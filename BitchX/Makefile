# $NetBSD: Makefile,v 1.2 2013/02/04 08:39:32 thomasklausner Exp $

DISTNAME=	BitchX-1.2-final
PKGNAME=	bitchx-1.2 # XXX ${DISTNAME:S|-final||:LC}
CATEGORIES=	chat
MASTER_SITES=	http://www.bitchx.ca/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bitchx.org/
COMMENT=	IRC client based on ircII

WRKSRC=			${WRKDIR}/${DISTNAME:S|-final||}

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKG_MANDIR}
CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	--with-plugins

USE_TOOLS+=		gmake pax
USE_LANGUAGES+=		c

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
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} install

do-install:
	cd ${WRKSRC} && pax -rwpam ${DESTDIR}${PREFIX}/bin/* ${PREFIX}/bin
	cd ${WRKSRC} && pax -rwpam ${DESTDIR}${PREFIX}/lib/* ${PREFIX}/lib
	cd ${WRKSRC} && pax -rwpam ${DESTDIR}${PREFIX}/share/* ${PREFIX}/share

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
