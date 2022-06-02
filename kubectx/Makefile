# $NetBSD$

DISTNAME=	kubectx-0.9.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ahmetb/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kubectx.dev/
COMMENT=	Faster way to switch between clusters and namespaces in kubectl
LICENSE=	apache-2.0

USE_TOOLS+=	bash:run

REPLACE_BASH+=	kubectx
REPLACE_BASH+=	kubens

INSTALLATION_DIRS=	bin

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/kubectx ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/kubens ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
