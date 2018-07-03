# $NetBSD: Makefile,v 1.17 2014/10/20 13:09:05 thomasklausner Exp $

DISTNAME=	dir2ogg-0.11.8
CATEGORIES=	audio
MASTER_SITES=	http://jak-linux.org/projects/dir2ogg/0.11/

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://jak-linux.org/projects/dir2ogg
COMMENT=	Command-line {wav,mp3,m4a} to ogg converter
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen

USE_LANGUAGES=		# none
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
REPLACE_PYTHON+=	${WRKSRC}/dir2ogg
NO_BUILD=		yes

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.11.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dir2ogg ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dir2ogg.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
