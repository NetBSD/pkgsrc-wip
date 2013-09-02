# $NetBSD: Makefile,v 1.1 2013/09/02 12:09:14 thomasklausner Exp $

# version number from setup.py
DISTNAME=		khal-0.1.0
CATEGORIES=		time net
MASTER_SITES=		https://github.com/geier/khal

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/geier/khal
COMMENT=		CLI calendar application built around CalDAV
LICENSE=		mit

GIT_REPOSITORIES=	khal
GIT_REPO.khal= 		git://github.com/geier/khal.git

WRKSRC=			${WRKDIR}/khal
EGG_NAME=		${DISTNAME}.dev
INSTALLATION_DIRS=	share/doc/khal

post-install:
	${INSTALL_DATA} ${WRKSRC}/khal.conf.sample ${DESTDIR}${PREFIX}/share/doc/khal

.include "../../lang/python/distutils.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
