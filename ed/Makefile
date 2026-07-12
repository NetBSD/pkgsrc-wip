# $NetBSD: Makefile,v 1.21 2022/01/21 02:27:04 wen Exp $

DISTNAME=		ed-1.22.5
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GNU:=ed/}
EXTRACT_SUFX=		.tar.lz

MAINTAINER=		drixter@e-utp.net
HOMEPAGE=		https://www.gnu.org/software/ed/ed.html
COMMENT=		GNU version of line-oriented text editor
LICENSE=		gnu-gpl-v3

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
USE_LANGUAGES=		c
USE_TOOLS+=		gmake

INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
