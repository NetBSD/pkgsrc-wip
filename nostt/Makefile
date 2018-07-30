# $NetBSD$

GITHUB_PROJECT=	nostt
DISTNAME=	1.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=sjmulder/}
DIST_SUBDIR=	${GITHUB_PROJECT}
AUTO_MKDIRS=	yes

MAINTAINER=	ik@sjmulder.nl
HOMEPAGE=	https://github.com/sjmulder/nostt/
COMMENT=	Command line NOS Teletekst reader
LICENSE=	2-clause-bsd

WRKSRC=	${WRKDIR}/nostt-1.0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nostt ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/nostt.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../www/curl/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
