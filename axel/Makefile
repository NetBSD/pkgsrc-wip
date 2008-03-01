# $NetBSD: Makefile,v 1.7 2008/03/01 14:39:13 asau Exp $
#

DISTNAME=		axel-1.0b
CATEGORIES=		net
MASTER_SITES=		http://wilmer.gaast.net/downloads/

MAINTAINER=		alchow@users.sourceforge.net
HOMEPAGE=		http://wilmer.gaast.net/downloads/
COMMENT=		HTTP/FTP download accelerator

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

INSTALLATION_DIRS=	bin etc ${PKGMANDIR}/man1
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/axelrc.example ${PKG_SYSCONFDIR}/axelrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/axel ${DESTDIR:Q}${PREFIX:Q}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${EGDIR}
	${INSTALL_DATA} ${WRKSRC:Q}/axelrc.example ${DESTDIR:Q}${EGDIR}
	${INSTALL_MAN} ${WRKSRC:Q}/axel.1 ${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
