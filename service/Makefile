# $NetBSD: Makefile,v 1.2 2012/10/07 16:22:56 asau Exp $

PKGNAME=		service-0.8
DISTNAME=		# empty
COMMENT=		Small tool to handle rc.d service scripts
CATEGORIES=		sysutils

MAINTAINER=		adam.hoka@gmail.com
HOMEPAGE=		http://irkmaffia.com/~replaced/
NO_CHECKSUM=		yes

INSTALLATION_DIRS=	bin
WRKSRC=			${WRKDIR}

SUBST_CLASSES+=			localbase
SUBST_MESSAGE.localbase=	Fixing localbase.
SUBST_STAGE.localbase=		post-extract
SUBST_FILES.localbase=		service.sh
SUBST_SED.localbase=		-e "s,/usr/pkg,${LOCALBASE},"


do-fetch:
	${CP} ${FILESDIR}/service.sh ${WRKSRC}

do-extract:
do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/service.sh ${DESTDIR}${PREFIX}/bin/service

.include "../../mk/bsd.pkg.mk"
