# $NetBSD: Makefile,v 1.2 2012/09/28 22:07:28 asau Exp $

DISTNAME=	e-uae-0.8.29-WIP4
PKGNAME=	e-uae-0.8.29wip4
CATEGORIES=	emulators
MASTER_SITES=	http://www.rcdrummond.net/uae/${DISTNAME}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://www.rcdrummond.net/uae/
COMMENT=	Enhanced Ubiquitous Amiga Emulator
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

CONFLICTS+=	uae-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "options.mk"

INSTALLATION_DIRS=	share/doc/uae \
			share/applications

post-install:
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.txt ${DESTDIR}${PREFIX}/share/doc/uae
	${INSTALL_DATA} ${FILESDIR}/e-uae.desktop ${DESTDIR}${PREFIX}/share/applications

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
