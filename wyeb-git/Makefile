# $NetBSD$

DISTNAME=	wyeb-0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=jun7/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wyeb.org/
COMMENT=	Vim-like webkit2gtk browser
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	wyeb
GIT_REPO.wyeb=		git://github.com/jun7/wyeb.git
WRKSRC=			${WRKDIR}/wyeb

BUILD_MAKE_FLAGS+=	EXTENSION_DIR=${PREFIX}/lib/wyebrowser
INSTALLATION_DIRS+=	bin lib/wyebrowser share/applications share/pixmaps

MAKE_FILE=	makefile
USE_TOOLS+=	gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wyeb ${DESTDIR}${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/ext.so ${DESTDIR}${PREFIX}/lib/wyebrowser
	${INSTALL_DATA} ${WRKSRC}/wyeb.desktop ${DESTDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/wyeb.png ${DESTDIR}${PREFIX}/share/pixmaps/

# only used in main configuration file, should these dependencies be optional?
DEPENDS+=	p5-File-MimeInfo-[0-9]*:../../devel/p5-File-MimeInfo
.include "../../textproc/discount/buildlink3.mk"

.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
