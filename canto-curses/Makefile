# $NetBSD$

GITHUB_PROJECT=	canto-curses
DISTNAME=	v${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-0.9.7
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=themoken/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/themoken/canto-curses/
COMMENT=	The curses (text) client for canto-daemon
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/canto-curses-0.9.7

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYDISTUTILSPKG=			YES

DEPENDS+=	canto-daemon-[0-9]*:../../wip/canto-daemon
DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
