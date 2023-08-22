# $NetBSD$

DISTNAME=	forgejo-src-1.20.3-0
PKGNAME=	${DISTNAME:S/-src//S/-0/.0/}
CATEGORIES=	www devel
MASTER_SITES=	https://codeberg.org/forgejo/forgejo/releases/download/v${DISTNAME:S/forgejo-src-//}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://forgejo.org/
COMMENT=	Git hosting software
LICENSE=	mit

INSTALLATION_DIRS=	share/example/forgejo

.include "go-modules.mk"

post-install:
.for f in ambiguous backport environment-to-ini fixtures invisible
	${RM} ${DESTDIR}${PREFIX}/bin/${f}
.endfor
	${MV} ${DESTDIR}${PREFIX}/bin/gitea ${DESTDIR}${PREFIX}/bin/forgejo
	${INSTALL_DATA} ${WRKSRC}/custom/conf/app.example.ini ${DESTDIR}${PREFIX}/share/example/forgejo

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
