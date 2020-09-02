# $NetBSD$

DISTNAME=	wmbattery-2.54
CATEGORIES=	x11
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dockapps.net/
COMMENT=	Dockapp that shows battery status
LICENSE=	gnu-gpl-v2

PATCHDIR=	${.CURDIR}/../../wip/wmbattery/patches
FILESDIR=	${.CURDIR}/../../wip/wmbattery/files

.include "options.mk"

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoreconf autoconf automake gmake pkg-config

pre-configure:
	${CP} \
	    ${FILESDIR}/envsys.c \
	    ${FILESDIR}/envsys.h \
	    ${WRKSRC}

	cd ${WRKSRC} && autoreconf -fi

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
