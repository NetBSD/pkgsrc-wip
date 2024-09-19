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

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_MESSAGE.config=	Honor user's CFLAGS and avoid hardcoded optimizations
SUBST_FILES.config=	config.mk
SUBST_SED.config+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.config+=	-e '/CFLAGS/s,-O3,,'

.include "../../mk/bsd.pkg.mk"
