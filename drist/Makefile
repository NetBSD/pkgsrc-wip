# $NetBSD$

DISTNAME=	drist-v1.04
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.bitreich.org/releases/drist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/drist
COMMENT=	Simple hosts deployment tool
LICENSE=	2-clause-bsd

USE_TOOLS+=	mktemp:run

DEPENDS+=	rsync-[0-9]*:../../net/rsync

MAKE_FLAGS+=	PREFIX="${PREFIX}"
MAKE_FLAGS+=	MANDIR="${PREFIX}/${PKGMANDIR}"

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/drist ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/drist.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
