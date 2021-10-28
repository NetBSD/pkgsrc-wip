# $NetBSD: Makefile,v 1.7 2014/04/03 01:21:22 outpaddling Exp $

DISTNAME=	APE-3.5.3.74
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	5d11d8d8f59ce8ffbe396d6b92476a76e6895916

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
