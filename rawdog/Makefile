# $NetBSD$

DISTNAME=	rawdog-2.23
CATEGORIES=	news
MASTER_SITES=	http://offog.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://offog.org/code/rawdog/
COMMENT=	RSS Aggregator Without Delusions Of Grandeur
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-feedparser<6.0.0:../../textproc/py-feedparser5

PYTHON_VERSIONS_ACCEPTED=	27
PYDISTUTILSPKG=			YES

INSTALLATION_DIRS+=	share/examples/rawdog

post-install:
	${INSTALL_DATA} ${WRKSRC}/config ${DESTDIR}${PREFIX}/share/examples/rawdog/
	${INSTALL_DATA} ${WRKSRC}/style.css ${DESTDIR}${PREFIX}/share/examples/rawdog/

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
