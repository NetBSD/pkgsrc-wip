# $NetBSD$

DISTNAME=	catpoint-v0.2
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	misc
MASTER_SITES=	ftp://bitreich.org/releases/catpoint/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/catpoint
COMMENT=	Simple point utilities to hold text presentations
LICENSE=	gnu-gpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

BUILDLINK_TRANSFORM+=	l:ncursesw:${BUILDLINK_LIBNAME.curses}

USE_LANGUAGES=	c99

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
