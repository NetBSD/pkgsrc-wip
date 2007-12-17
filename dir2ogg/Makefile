# $NetBSD: Makefile,v 1.1.1.1 2007/12/17 21:07:31 guigui2 Exp $
#

DISTNAME=	dir2ogg-0.11
CATEGORIES=	audio
MASTER_SITES=	http://jak-linux.org/projects/dir2ogg/0.11/

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://jak-linux.org/projects/dir2ogg/0.11/
COMMENT=	Command-line {wav,mp3,m4a} to ogg converter

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	24

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing paths.
SUBST_STAGE.path=	pre-build
SUBST_FILES.path=	${WRKSRC}/dir2ogg
SUBST_SED.path=         -e 's,/usr/bin/python,${PYTHONBIN},g'


do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dir2ogg ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dir2ogg.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/python/application.mk"
.include "../../audio/py-mutagen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
