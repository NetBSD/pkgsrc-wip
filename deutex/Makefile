# $NetBSD$

DISTNAME=	deutex-5.2.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Doom-Utils/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	deutex
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Doom-Utils/deutex
COMMENT=	Command-line tool for building Doom WAD files
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c99
# GNU make is required for man page generation (broken with BSD make)
TOOL_DEPENDS+=	asciidoc>=10.2:../../textproc/asciidoc
USE_TOOLS+=	autoconf automake gmake autoreconf
GNU_CONFIGURE=	yes

PLIST.bsd=		yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../mk/bsd.pkg.mk"
