# $NetBSD$

DISTNAME=	sent-1
CATEGORIES=	textproc
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tools.suckless.org/sent/
COMMENT=	Simple plaintext presentation tool
LICENSE=	mit

USE_TOOLS+=	bzip2:run	# for bunzip2

WRKSRC=		${WRKDIR}

DEPENDS+=	farbfeld-[0-9]*:../../wip/farbfeld	# for 2ff

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Adjust config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,/usr/X11R6,${X11BASE},'
SUBST_SED.makefile+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^CPPFLAGS *= ,CPPFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
# XXX: freetype2 is not needed, do not add it to CFLAGS.
SUBST_SED.makefile+=	-e 's,-I/usr/include/freetype2,,'

USE_LANGUAGES=	c99

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
