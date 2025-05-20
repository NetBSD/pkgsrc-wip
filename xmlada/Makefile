# $NetBSD: Makefile,v 1.0 2024/05/06 15:00:00 dkazankov Exp $

DISTNAME=	xmlada-${PKGVERSION_NOREV}
PKGNAME=	xmlada-25.0.0
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	xmlada
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/xmlada
COMMENT=	XML/Ada: An XML parser for Ada95
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

USE_LANGUAGES=	ada
# Xmlada 25 can still be built by GNAT 6, but other Adacore's 25 series libs can not.
# So for uniformity and compatibility we use minimum version which can build all libs.
GCC_REQD+=	13

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

SUBST_CLASSES+=		fixver
SUBST_STAGE.fixver=	pre-configure
SUBST_FILES.fixver=	./configure.in	./configure
SUBST_MESSAGE.fixver=	Fix version in configure
SUBST_SED.fixver=	-e 's,18.0w,25.0w,g'

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} include lib share \( -type f -or -type l \) -print | ${SORT};

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
