# $NetBSD$

GITHUB_PROJECT=	yamusic-tui
GITHUB_TAG=	b48abfca93ac6be0ab7a98659e1e290a20d39608
DISTNAME=	yamusic-tui
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

DOCDIR=	${PREFIX}/share/doc/${DISTNAME}
INSTALLATION_DIRS+=	share/doc/${DISTNAME}

post-install:
	${INSTALL_DATA}	${FILESDIR}/README.pkgsrc ${DESTDIR}${DOCDIR}/README

.include "go-modules.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
