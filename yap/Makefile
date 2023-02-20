# $NetBSD: Makefile,v 1.27 2017/10/09 08:52:04 wiz Exp $

DISTNAME=		YAP-6.3.4
PKGNAME=		${DISTNAME:tl}
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GITHUB:=vscosta/}
GITHUB_PROJECT=		yap-6.3
GITHUB_TAG=		${DISTNAME}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/vscosta/yap-6.3
COMMENT=		ISO-compliant Prolog

TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
DEPENDS+=		odbc-postgresql-[0-9]*:../../databases/odbc-postgresql

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		INDENT=${TRUE:Q}

.include "../../mk/bsd.prefs.mk"

# If it doesn't probe a c++0x compiler, it doesn't build "horus",
# which is apparently a belief propagation engine. There isn't any
# good way to detect in pkgsrc if the current compiler supports any
# particular dialect (at least as of this writing) and forcing a
# non-default compiler seems like overkill, so for now at least we'll
# approximate by OS.
PLIST_VARS+=		horus
.if ${OPSYS} != "OpenBSD"
PLIST.horus=		yes
.endif

.include "../../devel/cmake/build.mk"
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
