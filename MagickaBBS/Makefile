# $NetBSD$

DISTNAME=	MagickaBBS-0.2alpha1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cloudxtreme/}
GITHUB_TAG=	v0.2-alpha1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Cloudxtreme/MagickaBBS/
COMMENT=	Bulletin board system
LICENSE=	modified-bsd

USE_LANGUAGES=	c
USE_TOOLS+=	gmake pax

BUILD_DIRS=	jamlib Xmodem lua .

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/MagickaBBS
INSTALLATION_DIRS+=	share/examples/MagickaBBS

post-patch:
	cd ${WRKSRC} && \
		${LN} jamlib/Makefile.linux jamlib/Makefile && \
		${LN} Makefile.freebsd Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/magicka ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/MagickaBBS
	cd ${WRKSRC}/ansis_default && ${PAX} -pp -rw * ${DESTDIR}${PREFIX}/share/examples/MagickaBBS/ansis
	cd ${WRKSRC}/config_default && ${PAX} -pp -rw * ${DESTDIR}${PREFIX}/share/examples/MagickaBBS/config

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
