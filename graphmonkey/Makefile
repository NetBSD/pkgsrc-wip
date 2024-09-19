# $NetBSD: Makefile,v 1.5 2013/06/17 12:45:11 thomasklausner Exp $
#

DISTNAME=	GraphMonkey-1.7-src
PKGNAME=	${DISTNAME:tl:S/-src//1}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=graphmonkey/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://graphmonkey.sourceforge.net/
COMMENT=	GTK\#-based graphing calculator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config
INSTALL_ENV+=	BIN=${PREFIX}/bin SHARE=${PREFIX}/share

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	graphmonkey
SUBST_MESSAGE.prefix=	Fixing PREFIX.
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|1"
SUBST_STAGE.prefix=	post-patch

INSTALLATION_DIRS+=	bin share/pixmaps

post-install:
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.png \
		${DESTDIR}${PREFIX}/share/pixmaps

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
