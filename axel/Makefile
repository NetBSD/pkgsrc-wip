# $NetBSD: Makefile,v 1.2 2007/04/05 23:32:24 alchow Exp $
#

DISTNAME=		axel-1.0b
CATEGORIES=		net
MASTER_SITES=		http://wilmer.gaast.net/downloads/

MAINTAINER=		alchow@users.sourceforge.net
HOMEPAGE=		http://wilmer.gaast.net/downloads/
COMMENT=		HTTP/FTP download accelerator

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

INSTALLATION_DIRS=	bin etc ${PKGMANDIR}/man1
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/axelrc.example ${PKG_SYSCONFDIR}/axelrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/axel ${PREFIX:Q}/bin/
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC:Q}/axelrc.example ${EGDIR}
	${INSTALL_MAN} ${WRKSRC:Q}/axel.1 ${PREFIX:Q}/man/man1/

.include "../../mk/bsd.pkg.mk"
