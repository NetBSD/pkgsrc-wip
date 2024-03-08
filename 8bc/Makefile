# $NetBSD$

DISTNAME=	version_${PKGVERSION_NOREV}
PKGNAME=	8bc-2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=clausecker/}
GITHUB_TAG=	${DISTNAME}
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://github.com/clausecker/8bc/
COMMENT=	B compiler for the PDP-8
#LICENSE=	2-clause-bsd AND pdp8pal-license

TOOL_DEPENDS+=	groff-[0-9]*:../../textproc/groff

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_TOOLS+=	gmake sed patch nroff groff lex yacc
TOOLS_PATH.groff=	${PREFIX}/bin/groff

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	P=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
