# $NetBSD: Makefile,v 1.4 2012/11/13 23:20:30 othyro Exp $
#

PKGNAME=	netbsd-light-desktop-artwork-0.0
PKGREVISION=	1
DISTNAME=	lubuntu-artwork_0.27
CATEGORIES=	graphics
MASTER_SITES=	http://archive.ubuntu.com/ubuntu/pool/universe/l/lubuntu-artwork/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.netbsd.org/light-desktop
COMMENT=	Artwork and icon theme for NetBSD
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/lubuntu-artwork-0.27
NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOL+=	pax

INSTALLATION_DIRS=	share/netbsd-light-desktop/images \
			share/netbsd-light-desktop/wallpapers \
			share/lxpanel/images/ \
			share/themes/NetBSD-default

post-extract:
	mv ${WRKSRC}/usr/share/themes/Lubuntu-default \
		${WRKSRC}/usr/share/themes/NetBSD-default

do-install:
	${INSTALL_DATA} ${FILESDIR}/netbsd-light-desktop-logo.png \
		${DESTDIR}/${PREFIX}/share/netbsd-light-desktop/images/
	${INSTALL_DATA} \
		${WRKSRC}/usr/share/lubuntu/wallpapers/lubuntu-default-wallpaper.png \
		${DESTDIR}${PREFIX}/share/netbsd-light-desktop/wallpapers/netbsd-light-desktop-default-wallpaper.png
	${INSTALL_DATA} \
		${WRKSRC}/usr/share/lxpanel/images/lubuntu-background.png \
		${DESTDIR}${PREFIX}/share/lxpanel/images/netbsd-light-desktop-background.png
	cd  ${WRKSRC}/usr &&	\
	pax -rw -s ',.*.orig$$,,' \
		share/themes/NetBSD-default ${DESTDIR}${PREFIX}/

.include "../../mk/bsd.pkg.mk"
