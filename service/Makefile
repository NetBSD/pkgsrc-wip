# $NetBSD: Makefile,v 1.2 2012/10/07 16:22:56 asau Exp $

DISTNAME=		# empty
PKGNAME=		service-0.8
CATEGORIES=		sysutils

MAINTAINER=		adam.hoka@gmail.com
HOMEPAGE=		http://irkmaffia.com/~replaced/
COMMENT=		Small tool to handle rc.d service scripts

NO_CHECKSUM=		yes

INSTALLATION_DIRS=	bin
WRKSRC=			${WRKDIR}

SUBST_CLASSES+=			localbase
SUBST_MESSAGE.localbase=	Fixing localbase.
SUBST_STAGE.localbase=		post-extract
SUBST_FILES.localbase=		service.sh
SUBST_SED.localbase=		-e "s,/usr/pkg,${PREFIX},"


do-fetch:
	${CP} ${FILESDIR}/service.sh ${WRKSRC}

do-extract:
do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/service.sh ${DESTDIR}${PREFIX}/bin/service

.include "../../mk/bsd.pkg.mk"
