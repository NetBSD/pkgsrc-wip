# $NetBSD: Makefile,v 1.2 2009/05/20 00:58:40 thomasklausner Exp $
#

DISTNAME=	asymptote-1.56
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=asymptote/}
EXTRACT_SUFX=	.tgz
DISTFILES= ${DISTNAME}.src${EXTRACT_SUFX}

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://asymptote.sourceforge.net/
COMMENT=	Asymptote: a language for plotting/drawing

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=          c c++

CONFIGURE_ARGS+=	--enable-gc=system
USE_TOOLS+=   gmake perl
CFLAGS+= -DGC_NO_THREAD_REDIRECTS
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
