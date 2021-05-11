# $NetBSD: Makefile,v 1.7 2014/04/03 01:21:22 outpaddling Exp $

DISTNAME=	APE-3.5.3.29
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	9daa3d03e22d4f65755e5002f829fd32cba2e5e0

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/APE
COMMENT=	Another Programmer's Editor
LICENSE=	2-clause-bsd

DEPENDS=	webbrowser>=0:../../wip/webbrowser

INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

pre-build:
	cd ${WRKSRC} && ${MAKE} LOCALBASE=${PREFIX} depend

.include "../../wip/libpare/buildlink3.mk"
.include "../../wip/libxtend/buildlink3.mk"
.include "../../wip/twintk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
