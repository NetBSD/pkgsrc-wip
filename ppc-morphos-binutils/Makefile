# $NetBSD$

DISTNAME=	sdk-source-20191111
PKGNAME=	ppc-morphos-binutils-2.33.1
CATEGORIES=	cross
MASTER_SITES=	https://morphos-team.net/files/src/sdk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	js-pkgsrc@heap.zone
HOMEPAGE=	https://www.morphos-team.net/
COMMENT=	Binutils for ppc-morphos
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/sdk-source/binutils/binutils-2.33.1
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		xzcat gtar patch

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
CONFIGURE_ARGS+=	--target=ppc-morphos
CONFIGURE_ARGS+=	--enable-plugins=no
CONFIGURE_ARGS+=	--disable-initfini-array
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS} -DMORPHOS_TARGET"

post-extract:
	${RUN} cd ${WRKDIR}/sdk-source/binutils && \
		${XZCAT} binutils-2.33.1.tar.xz | ${GTAR} xf -

do-patch:
	${RUN} cd ${WRKDIR}/sdk-source/binutils && \
		${PATCH} -p0 <binutils-2.33.1-morphos.diff

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/bsd.pkg.mk"
