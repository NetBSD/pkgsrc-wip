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

USE_LANGUAGES=	# none

REPLACE_BASH+=	kubectx
REPLACE_BASH+=	kubens

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/completions

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/kubectx ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/kubens ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/completion/kubectx.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions/kubectx
	${INSTALL_DATA} ${WRKSRC}/completion/kubens.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions/kubens
	${INSTALL_DATA} ${WRKSRC}/completion/kubectx.fish ${DESTDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/completion/kubens.fish ${DESTDIR}${PREFIX}/share/fish/completions

.include "../../mk/bsd.pkg.mk"
