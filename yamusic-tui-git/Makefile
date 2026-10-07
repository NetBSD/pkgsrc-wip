# $NetBSD$

GITHUB_PROJECT=	yamusic-tui
GITHUB_TAG=	v0.8.0
DISTNAME=	yamusic-tui-0.8.0
PKGNAME=	yamusic-tui-git
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=DECE2183/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/DECE2183/yamusic-tui
COMMENT=	Terminal user interface for the YAMusic music server
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config
GO_VERSION_REQD=	122
PKGSRC_MKPIE=		no
GOFLAGS+=		-tags nomedia
DEPENDS+=		alsa-plugins-oss>=1.2.7.1:../../audio/alsa-plugins-oss

DOCDIR=	${PREFIX}/share/doc/${GITHUB_PROJECT}
INSTALLATION_DIRS+=	share/doc/${GITHUB_PROJECT}

post-install:
	${INSTALL_DATA}	${FILESDIR}/README.pkgsrc ${DESTDIR}${DOCDIR}/README

.include "go-modules.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
