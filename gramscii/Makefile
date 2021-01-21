# $NetBSD$

DISTNAME=	gramscii-v0.4
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	misc
MASTER_SITES=	ftp://bitreich.org/releases/gramscii/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/gramscii
COMMENT=	Simple editor for ASCII box-and-arrow charts
LICENSE=	gnu-gpl-v3

MAKE_FLAGS+=	PREFIX="${PREFIX}"
MAKE_FLAGS+=	MANDIR="${PREFIX}/${PKGMANDIR}"

USE_LANGUAGES=	c99

.include "../../mk/bsd.pkg.mk"
