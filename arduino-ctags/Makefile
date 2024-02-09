# $NetBSD$

DISTNAME=	arduino-ctags-${GITHUB_TAG:S/-arduino11//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=arduino/}
GITHUB_PROJECT=	ctags
GITHUB_TAG=	5.8-arduino11

MAINTAINER=	krz.lasocki@gmail.com
HOMEPAGE=	https://github.com/arduino/ctags
COMMENT=	Arduino ctags, based on Exuberant ctags
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 \
			arduino15/packages/builtin/tools/ctags/${GITHUB_TAG}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ctags \
		${DESTDIR}${PREFIX}/arduino15/packages/builtin/tools/ctags/${GITHUB_TAG}
	${INSTALL_PROGRAM} ${WRKSRC}/ctags \
		${DESTDIR}${PREFIX}/bin/arduino-ctags
	${INSTALL_MAN} ${WRKSRC}/ctags.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/arduino-ctags.1

.include "../../mk/bsd.pkg.mk"
