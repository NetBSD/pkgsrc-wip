# $NetBSD: Makefile,v 1.2 2018/09/08 14:10:52 leot Exp $

DISTNAME=	gophervalidator-0.1
CATEGORIES=	net
MASTER_SITES=	http://codemadness.org/releases/gophervalidator/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://codemadness.org/git/sfeed/file/README.html
COMMENT=	Gopher validator and happy helper
LICENSE=	isc

GIT_REPOSITORIES=		gophervalidator
GIT_REPO.gophervalidator=	git://git.codemadness.org/gophervalidator
WRKSRC=				${WRKDIR}/gophervalidator

USE_LANGUAGES=	c99

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Adjust Makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e '/^LDFLAGS/s,^,\#,'

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gophervalidator ${DESTDIR}${PREFIX}/bin

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
