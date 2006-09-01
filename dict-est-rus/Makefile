# $NetBSD: Makefile,v 1.2 2006/09/01 23:38:07 cheusov Exp $

DISTNAME=	er-dict-gtk-0.23
PKGNAME=	dict-est-rus-0.23
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=er-dict/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sf.net/projects/er-dict
COMMENT=	DICTD data for Estonian-Russian dictionary

DEPENDS+=	dict-server>=1.9.14:../../wip/dict-server
BUILD_DEPENDS+=	dict-server>=1.10.2:../../wip/dict-server

DICTD_DB_DIR=		${PREFIX}/share/dictd
INSTALLATION_DIRS=	${DICTD_DB_DIR}

do-configure:
	${CP} files/build_estonian_et_ru ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SH} build_estonian_et_ru && \
	dictzip *.dict

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.dict.dz ${WRKSRC}/*.index \
		${DICTD_DB_DIR}

.include "../../mk/bsd.pkg.mk"
