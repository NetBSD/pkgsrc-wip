# $NetBSD$

DISTNAME=		getssl-2.48
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=srvrco/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/srvrco/getssl/
COMMENT=		Obtain free SSL certificates from letsencrypt ACME server
LICENSE=		gnu-gpl-v3

USE_LANGUAGES=		# none
USE_TOOLS+=		bash:run
REPLACE_BASH+=		getssl
NO_BUILD=		yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	getssl
SUBST_VARS.paths=	PKG_SYSCONFDIR

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/getssl ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
