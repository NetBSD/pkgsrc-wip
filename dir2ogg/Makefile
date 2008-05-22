# $NetBSD: Makefile,v 1.6 2008/05/22 15:38:46 tnn2 Exp $
#

DISTNAME=	dir2ogg-0.11.5
CATEGORIES=	audio
MASTER_SITES=	http://jak-linux.org/projects/dir2ogg/0.11/

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://jak-linux.org/projects/dir2ogg
COMMENT=	Command-line {wav,mp3,m4a} to ogg converter

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	25 24

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

REPLACE_PYTHON+=	${WRKSRC}/dir2ogg
NO_BUILD=yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dir2ogg ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dir2ogg.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/python/application.mk"
.include "../../audio/py-mutagen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
