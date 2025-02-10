# $NetBSD: Makefile,v 1.0 2024/05/06 15:00:00 dkazankov Exp $

PKGNAME=	xmlada-25.0.0
CATEGORIES=	devel
COMMENT=	XML/Ada: An XML parser for Ada95

DISTNAME=	xmlada-${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	xmlada

HOMEPAGE=	https://github.com/AdaCore/xmlada
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	ada

GCC_REQD+=	13

SUBST_CLASSES+=		fixver
SUBST_STAGE.fixver=	pre-configure
SUBST_FILES.fixver=	./configure.in	./configure
SUBST_MESSAGE.fixver=	Fix version in configure
SUBST_SED.fixver=	-e 's,18.0w,25.0w,g'

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX} --enable-shared=yes

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} include lib share \( -type f -or -type l \) -print | ${SORT};

.include "../../lang/gcc13-gnat-libs/buildlink3.mk"
.include "../../devel/gprbuild/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
