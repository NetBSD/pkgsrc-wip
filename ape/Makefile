# $NetBSD: Makefile,v 1.7 2014/04/03 01:21:22 outpaddling Exp $

DISTNAME=	APE-3.5.3.146
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	1683f6cd3de24316fd6136daab34f9691860e5ab

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/APE
COMMENT=	Another Programmer's Editor
LICENSE=	2-clause-bsd

DEPENDS=	webbrowser>=0:../../wip/webbrowser

MAKE_ENV+=		VERSION=${PKGVERSION}
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

LDFLAGS.SunOS+=		-lresolv -lsocket -lnsl

pre-build:
	cd ${WRKSRC} && ${MAKE} LOCALBASE=${PREFIX} depend

.include "../../wip/libpare/buildlink3.mk"
.include "../../wip/libxtend/buildlink3.mk"
.include "../../wip/twintk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
