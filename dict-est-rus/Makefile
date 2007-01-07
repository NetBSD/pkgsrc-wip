# $NetBSD: Makefile,v 1.5 2007/01/07 14:01:51 cheusov Exp $

DISTNAME=	er-dict-gtk-0.23
PKGNAME=	dict-est-rus-0.23
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=er-dict/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/er-dict
COMMENT=	DICTD data for Estonian-Russian dictionary

BUILD_DEPENDS+=	dict-server>=1.10.2:../../wip/dict-server
BUILD_DEPENDS+=	metamail>=1.10.2:../../mail/metamail
DEPENDS+=	dict-server>=1.9.14:../../wip/dict-server

DICTD_DB_DIR=		${PREFIX}/share/dictd
INSTALLATION_DIRS=	${DICTD_DB_DIR}

do-configure:
	cp files/build_estonian_et_ru ${WRKSRC}

do-build:
	cd ${WRKSRC} && sh build_estonian_et_ru && \
	${LOCALBASE}/bin/dictzip *.dict

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.dict.dz ${WRKSRC}/*.index \
		${DICTD_DB_DIR}

.include "../../mk/bsd.pkg.mk"
