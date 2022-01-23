# $NetBSD: Makefile,v 1.8 2012/09/24 16:56:41 asau Exp $
#

DISTNAME=		axel-1.0b
CATEGORIES=		net
MASTER_SITES=		https://wilmer.gaa.st/downloads/

MAINTAINER=		alchow@users.sourceforge.net
HOMEPAGE=		https://github.com/axel-download-accelerator/axel
COMMENT=		HTTP/FTP download accelerator

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--prefix=${PREFIX}

INSTALLATION_DIRS=	bin etc ${PKGMANDIR}/man1
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/axelrc.example ${PKG_SYSCONFDIR}/axelrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/axel ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/axelrc.example ${DESTDIR}${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/axel.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
