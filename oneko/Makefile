# $NetBSD$

DISTNAME=		oneko-1.2
#PKGNAME=		oneko-1.2.1
CATEGORIES=		x11 games
GIT_REPOSITORIES=	oneko
GIT_REPO.oneko=		https://c.n0.is/git/oneko.git
#MASTER_SITES=		https://d.n0.is/pub/oneko/
#EXTRACT_SUFX=		.pax.Z

MAINTAINER=		ng0@n0.is
COMMENT=		Neko (cat) or other animals follow your pointer
LICENSE=		2-clause-bsd

WRKSRC=			${WRKDIR}/oneko

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/oneko ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/oneko.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libXext/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
