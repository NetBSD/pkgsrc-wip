# $NetBSD: Makefile,v 1.2 2014/09/10 09:01:41 thomasklausner Exp $

DISTNAME=	yaupspe-r38
PKGNAME=	${DISTNAME:S/-r/-/}
CATEGORIES=	emulators
MASTER_SITES=	http://yaupspe.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/yaupspe/
COMMENT=	Cross-platform PSP emulator, based on Potemkin
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake pkg-config
INSTALLATION_DIRS+=	bin

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC}/src && \
		${INSTALL_PROGRAM} yaupspe ${DESTDIR}${PREFIX}/bin

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
