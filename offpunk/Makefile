# $NetBSD: Makefile,v 1.94 2024/10/20 09:56:27 leot Exp $

DISTNAME=	offpunk-2.4
CATEGORIES=	net python
MASTER_SITES=	-https://git.sr.ht/~lioploum/offpunk/archive/v${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://offpunk.net
COMMENT=	Offline first command-line browser for the smolnet
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/${PKGBASE}-v${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser
DEPENDS+=	${PYPKGPREFIX}-readability-lxml-[0-9]*:../../wip/py-readability-lxml
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle

REPLACE_PYTHON+=	*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
