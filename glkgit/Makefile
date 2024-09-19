# $NetBSD: Makefile,v 1.10 2012/12/12 10:44:37 thomasklausner Exp $
#

GITHUB_PROJECT=		Git
DISTNAME=		${GITHUB_TAG}
PKGNAME=		glkgit-1.3.5
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=DavidKinder/}
DIST_SUBDIR=		${GITHUB_PROJECT}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITE_GITHUB:=DavidKinder/Git/}
COMMENT=		Interpreter for Glulx interactive fiction

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV:S/glkg/G/}
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/git ${DESTDIR}${PREFIX}/bin/glkgit

PKG_OPTIONS_VAR=	PKG_OPTIONS.glkgit
.include "../../wip/glkloader/glk-options.mk"
.include "../../mk/bsd.options.mk"
.include "../../wip/glkloader/glk-depends.mk"

.include "../../mk/bsd.pkg.mk"
