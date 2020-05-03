# $NetBSD$

DISTNAME=	catpoint-1.0
CATEGORIES=	misc
MASTER_SITES=	ftp://bitreich.org/releases/catpoint/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/catpoint
COMMENT=	Simple point utilities to hold text presentations
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	catpoint
GIT_REPO.catpoint=	git://bitreich.org/catpoint/
WRKSRC=			${WRKDIR}/catpoint

MAKE_FLAGS+=	INCS=-I${BUILDLINK_INCDIRS.curses:Q}
MAKE_FLAGS+=	LIBS=${BUILDLINK_LDADD.curses:Q}

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Adjusting config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.makefile+=	-e '/^CFLAGS/ s,-Os,,'
SUBST_SED.makefile+=	-e '/CFLAGS/ s,$$,$${INCS},'

USE_LANGUAGES=	c99

.include "../../wip/mk/git-package.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
