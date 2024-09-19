# $NetBSD: Makefile,v 1.2 2012/10/07 16:07:54 asau Exp $

DISTNAME=	ssu-0.8
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.yuv.info/~wavexx/hacks/ssu/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yuv.info/~wavexx/hacks/ssu/
COMMENT=	Command-line access to local and remote Source Safe/VSS repositories

REPLACE_PERL=	ss ssserv
USE_LANGUAGES=	# none
USE_TOOLS+=	perl

do-build:

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ss ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ssserv ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ssu
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/ssu

.include "../../mk/bsd.pkg.mk"
