# $NetBSD$

DISTNAME=	1.51
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=espeak-ng/}
GITHUB_PROJECT=	espeak-ng
GITHUB_TAG=	refs/tags/1.51
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/espeak-ng/espeak-ng/
COMMENT=	Open source speech synthesizer
LICENSE=	gnu-gpl-v3 AND apache-2.0 AND 2-clause-bsd AND unicode

PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
WRKSRC=		${WRKDIR}/${PKGNAME}

USE_TOOLS+=	autoconf automake autoreconf gmake
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

# -D_NETBSD_SOURCE for mkstemp in /usr/include/stdlib.h
.if ${OPSYS} == "NetBSD"
CFLAGS+=	-D_NETBSD_SOURCE -DOS_NETBSD
.endif

CONFIGURE_ARGS+=	CFLAGS=${CFLAGS:M*:Q}

PKGCONFIG_OVERRIDE+=	espeak-ng.pc.in

DEPENDS+=	mbrola-[0-9]*:../../audio/mbrola

# Makefile.am: error: required file './AUTHORS' not found
pre-configure:
	set -e; cd ${WRKSRC} && touch AUTHORS NEWS && autoreconf -fi

.include "../../audio/pcaudiolib/buildlink3.mk"
.include "options.mk"
.include "../../mk/bsd.pkg.mk"
