# $NetBSD$

PKGNAME=	texlive-tlpdb-1.0
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	TeX Live package database

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	share/tlpkg

do-build:
	${TOUCH} ${WRKDIR}/texlive.tlpdb

do-install:
	${INSTALL_DATA} ${WRKDIR}/texlive.tlpdb \
		${DESTDIR}${PREFIX}/share/tlpkg/

.include "../../mk/bsd.pkg.mk"
