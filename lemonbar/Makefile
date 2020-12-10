# $NetBSD$

DISTNAME=	lemonbar-1.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=LemonBoy/}
GITHUB_PROJECT=	bar
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	hopkinsza@gmail.com
HOMEPAGE=	https://github.com/LemonBoy/bar
COMMENT=	Featherweight lemon-scented bar
LICENSE=	mit

USE_TOOLS+=	gmake pod2man

AUTO_MKDIRS=	yes

# Add `doc' target to lemonbar's `all'.
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing Makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e 's/^all: .*$$/& doc/'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lemonbar ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/lemonbar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
