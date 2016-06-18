# $NetBSD$

DISTNAME=	xjadeo-0.8.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=x42/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xjadeo.sourceforge.net/
COMMENT=	X JAck viDEo mOnitor
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

USE_TOOLS=	automake aclocal autoheader autoconf pkg-config

GNU_CONFIGURE=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} ./autogen.sh

.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
