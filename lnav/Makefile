# $NetBSD: Makefile,v 1.37 2024/11/14 22:21:43 wiz Exp $

DISTNAME=	lnav-0.12.4
CATEGORIES=	sysutils textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tstack/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lnav.org/
COMMENT=	Log file navigator, an enhanced log viewer
LICENSE=	2-clause-bsd

GNU_CONFIGURE=		yes
GNU_CONFIGURE_ICONV=	no
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash:build gmake

# Force it -- configure thinks it can build with c++17
# but the program uses alloca() so depends on the gnu feature set
FORCE_CXX_STD=	gnu++17

GCC_REQD+=	8

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
