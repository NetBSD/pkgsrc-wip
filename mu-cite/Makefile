# $NetBSD: Makefile,v 1.6 2014/06/15 13:29:21 makoto Exp $

DISTNAME=	mu-cite-0.20240802
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=cvs-m17n-org/}
GITHUB_TAG=	62d42d2ef18a89bb109582f3b9466d46f9e7d4a0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://emacs-21.ki.nu/application/mu-cite.html
COMMENT=	Mail (MUA) companion to cite other's mail
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/MU-CITE-${GITHUB_TAG}

SUBST_CLASSES+=		dest
SUBST_STAGE.dest=	pre-build
SUBST_MESSAGE.dest=	replacing for dest-dir
SUBST_SED.dest=		-e 's|@@PREFIX@@|${DESTDIR}${PREFIX}|'
SUBST_FILES.dest+=	Makefile

EMACS_VERSIONS_INCOMPATIBLE=	emacs20 xemacs214 xemacs215 xemacs214nox xemacs215nox

.include "../../editors/emacs/modules.mk"

DEPENDS+=		${EMACS_PKGNAME_PREFIX}flim-[0-9]*:../../devel/flim
DEPENDS+=		${EMACS_PKGNAME_PREFIX}bbdb-[0-9]*:../../misc/bbdb3
MAKE_DIRS+=		${PREFIX}/share/doc/mu-cite
AUTO_MKDIRS=		yes

do-build:
	cd ${WRKSRC} && ${MAKE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.en ${DESTDIR}${PREFIX}/share/doc/mu-cite
	${INSTALL_DATA} ${WRKSRC}/NEWS      ${DESTDIR}${PREFIX}/share/doc/mu-cite

.include "../../mk/bsd.pkg.mk"
