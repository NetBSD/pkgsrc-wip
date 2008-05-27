# $NetBSD: Makefile,v 1.1.1.1 2008/05/27 13:28:59 hoka_adam Exp $

PKGNAME=		service-0.8
DISTNAME=		# empty
COMMENT=		Small tool to handle rc.d service scripts
CATEGORIES=		sysutils

PKG_DESTDIR_SUPPORT=	user-destdir

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
