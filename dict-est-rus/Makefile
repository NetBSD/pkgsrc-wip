# $NetBSD: Makefile,v 1.10 2012/09/28 21:24:36 asau Exp $

DISTNAME=	er-dict-gtk-0.23
PKGNAME=	${DISTNAME:S/er-dict-gtk/dict-est-rus/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=er-dict/}
EXTRACT_SUFX=	.tar.bz2
LICENSE=	gnu-gpl-v2

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/er-dict
COMMENT=	DICTD data for Estonian-Russian dictionary

BUILD_DEPENDS+=		dict-server>=1.10.2:../../textproc/dict-server
BUILD_DEPENDS+=		metamail>=1.10.2:../../mail/metamail
DEPENDS+=		dict-server>=1.9.14:../../textproc/dict-server

DICTD_DB_DIR=		${PREFIX}/share/dictd
INSTALLATION_DIRS=	${DICTD_DB_DIR}

do-configure:
	cp files/build_estonian_et_ru ${WRKSRC}

do-build:
	cd ${WRKSRC} && sh build_estonian_et_ru && \
	${PREFIX}/bin/dictzip *.dict

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.dict.dz ${WRKSRC}/*.index \
		${DESTDIR}${DICTD_DB_DIR}

.include "../../mk/bsd.pkg.mk"
