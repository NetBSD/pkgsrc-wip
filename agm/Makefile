# $NetBSD$

DISTNAME=	agm-1.3.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/linux/games/amusements/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.ibiblio.org/pub/linux/games/amusements/
COMMENT=	Multiple-word anagram search program
LICENSE=	generic-nonlicense

SUBST_CLASSES+=		rcsids
SUBST_MESSAGE.rcsids=	Strip RCS IDs as they cause problems when patching.
SUBST_STAGE.rcsids=	pre-patch
SUBST_FILES.rcsids+=	gobble.c
SUBST_FILES.rcsids+=	listfuncs.c
SUBST_FILES.rcsids+=	main.c
SUBST_FILES.rcsids+=	output.c
SUBST_FILES.rcsids+=	process.c
SUBST_FILES.rcsids+=	progress.c
SUBST_FILES.rcsids+=	sort.c
SUBST_FILES.rcsids+=	wordfuncs.c
SUBST_SED.rcsids=	-e "s!.Revision: !Revision: !"

MAKE_FLAGS+=	BINDIR=${PREFIX}/bin
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	WORDDIR=${PREFIX}/share/agm
MAKE_FLAGS+=	CC=${CC}

INSTALL_TARGET=		install install-words

REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	/usr/bin/wish
REPLACE.wish.new=	${LOCALBASE}/bin/wish
REPLACE_FILES.wish=	xagm

.include "../../mk/bsd.pkg.mk"
