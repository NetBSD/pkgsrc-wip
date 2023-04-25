# $NetBSD: Makefile,v 1.13 2020/04/27 04:22:22 rillig Exp $

DISTNAME=	mg-20230406
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=hboetes/}
GITHUB_PROJECT=	mg
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://github.com/hboetes/mg
COMMENT=	Small, fast, public domain EMACS style editor

#FAKE_NCURSES=	yes
USE_TOOLS+=	install gmake pkg-config
MAKE_ENV+=	prefix=${PREFIX}
MAKE_FILE=	GNUmakefile

CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CONFLICTS+=	mg2a-[0-9]*

BUILDLINK_TRANSFORM+=	rm:-Werror

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Adjusting path.
SUBST_FILES.path=	GNUmakefile mg.1
SUBST_SED.path=		-e "s|/usr/local|${PREFIX}|g"
SUBST_SED.path+=	-e "s|/usr/share/doc|${PREFIX}/share/doc|g"
SUBST_SED.path+=	-e "s|/usr/bin/pkg-config|pkg-config|g"

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MLinux-*-*)
.include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
