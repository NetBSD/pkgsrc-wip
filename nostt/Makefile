# $NetBSD$

GITHUB_PROJECT=	nostt
DISTNAME=	1.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=sjmulder/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	ik@sjmulder.nl
HOMEPAGE=	https://github.com/sjmulder/nostt/
COMMENT=	Command line NOS Teletekst reader
LICENSE=	2-clause-bsd

WRKSRC=	${WRKDIR}/nostt-1.1

.include "../../www/curl/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
