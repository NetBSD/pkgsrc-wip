# $NetBSD: Makefile,v 1.5 2012/10/03 15:09:59 asau Exp $

DISTNAME=	mu-cite-201202272330
CATEGORIES=	mail
MASTER_SITES=	http://www.jpl.org/elips/mu/snapshots/

MAINTAINER=	packages@ki.nu
HOMEPAGE=	http://emacs-21.ki.nu/application/mu-cite.html
COMMENT=	Mail (MUA) companion to cite other's mail
LICENSE=	gnu-gpl-v2

SUBST_CLASSES+=	dest
SUBST_STAGE.dest=	pre-build
SUBST_MESSAGE.dest=	replacing for dest-dir
SUBST_SED.dest=		-e 's|@@PREFIX@@|${DESTDIR}${PREFIX}|'
SUBST_FILES.dest+=	Makefile

.include "../../editors/emacs/modules.mk"

DEPENDS+=		flim-[0-9]*:../../devel/flim
DEPENDS+=		bbdb-[0-9]*:../../misc/bbdb
MAKE_DIRS+=		${PREFIX}/share/doc/mu-cite
AUTO_MKDIRS=		yes

do-build:
		(cd ${WRKSRC} && ${MAKE})

post-install:
		${INSTALL_DATA} ${WRKSRC}/README.en ${DESTDIR}${PREFIX}/share/doc/mu-cite
		${INSTALL_DATA} ${WRKSRC}/NEWS      ${DESTDIR}${PREFIX}/share/doc/mu-cite

.include "../../mk/bsd.pkg.mk"
