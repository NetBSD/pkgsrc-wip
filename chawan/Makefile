# $NetBSD$

DISTNAME=	v0.4.4
PKGNAME=	chawan-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://git.sr.ht/~bptato/chawan/archive/
DIST_SUBDIR=	chawan

MAINTAINER=	ivan@ivanpollak.com
HOMEPAGE=	https://chawan.net/
COMMENT=	TUI web browser with CSS, inline image and JavaScript support
LICENSE=	unlicense

TOOL_DEPENDS+=	pkgconf-[0-9]*:../../devel/pkgconf

WRKSRC=		${WRKDIR}/chawan-${DISTNAME}

USE_TOOLS+=	gmake pkg-config
MAKE_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../lang/nim/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../archivers/brotli/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../devel/pkgconf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
