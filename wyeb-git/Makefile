# $NetBSD$

DISTNAME=	wyeb-0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=jun7/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wyeb.org/
COMMENT=	Vim-like webkit2gtk browser
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	wyeb
GIT_REPO.wyeb=		git://github.com/jun7/wyeb.git
WRKSRC=			${WRKDIR}/wyeb

BUILD_MAKE_FLAGS+=	DISTRONAME=pkgsrc
BUILD_MAKE_FLAGS+=	DISTROURI=https://www.pkgsrc.org/
INSTALLATION_DIRS+=	bin lib/wyebrowser share/applications share/pixmaps

MAKE_FILE=	makefile
USE_TOOLS+=	gmake pkg-config

# only used in main configuration file, should these dependencies be optional?
DEPENDS+=	p5-File-MimeInfo-[0-9]*:../../devel/p5-File-MimeInfo
.include "../../textproc/discount/buildlink3.mk"

.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
