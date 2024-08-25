# $NetBSD$

DISTNAME=	sxcs-1.1.0
CATEGORIES=	x11
MASTER_SITES=	-https://codeberg.org/NRK/sxcs/archive/v${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://codeberg.org/NRK/sxcs
COMMENT=	Minimal X11 Color Picker and Magnifier
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/sxcs

INSTALLATION_DIRS+=	bin \
			${PKGMANDIR}/man1 \
			share/zsh/site-functions

do-build:
	cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} -o sxcs sxcs.c -s -lX11 -lXcursor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sxcs ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sxcs.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/etc/zsh-completion/_sxcs \
			${DESTDIR}${PREFIX}/share/zsh/site-functions/_sxcs

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
