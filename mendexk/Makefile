# $NetBSD$

.include "../../print/texlive/Makefile.common"

PKGNAME=	mendexk-2.6f
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asciidwango.github.io/ptex/base/sources.html
COMMENT=	Japanese index processor
LICENSE=	modified-bsd

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/mendexk

WRKSRC=	${WRKDIR}/${DISTNAME}/texk/mendexk

CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-ptexenc

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/ptexenc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
