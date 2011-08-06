# $NetBSD: Makefile,v 1.12 2011/08/06 19:13:34 guigui2 Exp $
#

DISTNAME=			dir2ogg-0.11.8
CATEGORIES=			audio
MASTER_SITES=			http://jak-linux.org/projects/dir2ogg/0.11/

MAINTAINER=			netbsd@guigui2.net
HOMEPAGE=			http://jak-linux.org/projects/dir2ogg
COMMENT=			Command-line {wav,mp3,m4a} to ogg converter
LICENSE=			gnu-gpl-v2

PKG_DESTDIR_SUPPORT=		user-destdir

USE_LANGUAGES=			# none
PYTHON_VERSIONS_ACCEPTED=	27 26 25 24
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
