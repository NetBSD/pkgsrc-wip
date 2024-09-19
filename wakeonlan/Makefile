# $NetBSD$

DISTNAME=	wakeonlan-0.41
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=jpoliv/}
GITHUB_TAG=	wakeonlan-${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/jpoliv/wakeonlan
COMMENT=	Wake up computers via wake-on-LAN magic packets
LICENSE=	artistic-2.0

USE_LANGUAGES=	# none
USE_TOOLS=	perl perl:run

REPLACE_PERL+=	wakeonlan

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-configure:
	cd ${WRKSRC} && ${PERL5} Makefile.PL

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/blib/script/wakeonlan ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/blib/man1/wakeonlan.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
