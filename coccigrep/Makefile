# $NetBSD: Makefile,v 1.16 2020/01/26 17:32:13 rillig Exp $

DISTNAME=	coccigrep-1.20
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=regit/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://home.regit.org/software/coccigrep/
COMMENT=	Semantic grep for the C language
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	coccinelle-[0-9]*:../../wip/coccinelle

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/coccigrep.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
