# $NetBSD: Makefile,v 1.14 2012/09/28 21:24:36 asau Exp $
#

DISTNAME=			dir2ogg-0.11.8
CATEGORIES=			audio
MASTER_SITES=			http://jak-linux.org/projects/dir2ogg/0.11/

MAINTAINER=			netbsd@guigui2.net
HOMEPAGE=			http://jak-linux.org/projects/dir2ogg
COMMENT=			Command-line {wav,mp3,m4a} to ogg converter
LICENSE=			gnu-gpl-v2

USE_LANGUAGES=			# none
INSTALLATION_DIRS=		bin ${PKGMANDIR}/man1
REPLACE_PYTHON+=		${WRKSRC}/dir2ogg
NO_BUILD=			yes

.include "../../audio/py-mutagen/buildlink3.mk"
.include "../../lang/python/application.mk"

do-install:
				${INSTALL_SCRIPT} ${WRKSRC}/dir2ogg \
					${DESTDIR}${PREFIX}/bin
				${INSTALL_MAN} ${WRKSRC}/dir2ogg.1 \
					${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
