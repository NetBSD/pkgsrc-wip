# $NetBSD$

DISTNAME=	ttyplot-1.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=tenox7/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/tenox7/ttyplot/
COMMENT=	Realtime plotting utility for terminals
LICENSE=	unlicense

# Adjust Makefile
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Fixing Makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e '/^CFLAGS/ s,-O3,,'
SUBST_SED.makefile+=	-e 's,^CFLAGS *= ,CFLAGS += ,'

DOCDIR=		share/doc/ttyplot

AUTO_MKDIRS=		yes
INSTALLATION_DIRS+=	bin ${DOCDIR}

do-install:
	${RUN}${INSTALL_PROGRAM} ${WRKSRC}/ttyplot ${DESTDIR}${PREFIX}/bin
	${RUN}${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
