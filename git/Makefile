# $NetBSD: Makefile,v 1.9 2012/09/29 00:50:35 asau Exp $
#

DISTNAME=		git-110
PKGNAME=		glkgit-1.1.0
CATEGORIES=		games
MASTER_SITES=		http://diden.net/if/git/releases/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://diden.net/if/git/
COMMENT=		Interpreter for Glulx interactive fiction

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV:S/glk//}
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR:Q}

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/git ${DESTDIR}${PREFIX}/bin/glkgit

PKG_OPTIONS_VAR=	PKG_OPTIONS.glkgit
.include "../../wip/glkloader/glk-options.mk"
.include "../../mk/bsd.options.mk"
.include "../../wip/glkloader/glk-depends.mk"

.include "../../mk/bsd.pkg.mk"
