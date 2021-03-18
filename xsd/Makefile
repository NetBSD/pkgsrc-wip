# $NetBSD: Makefile,v 1.39 2021/01/01 08:24:41 ryoon Exp $

DISTNAME=		xsd-4.0.0+dep
PKGNAME=		xsd-4.0.0
CATEGORIES=		devel textproc
MASTER_SITES=		https://www.codesynthesis.com/download/xsd/4.0/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.codesynthesis.com/products/xsd/
COMMENT=		W3C XML Schema to C++ data binding compiler
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		bash gmake gm4
USE_LANGUAGES+=		c c++
MAKE_FILE=		makefile
INSTALL_MAKE_FLAGS=	install_prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	install_man_dir=${DESTDIR}${PREFIX}/${PKGMANDIR}

# rename to not clash with mono
post-install:
	mv ${DESTDIR}${PREFIX}/bin/xsd ${DESTDIR}${PREFIX}/bin/xsdcxx
	mv ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xsd.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xsdcxx.1

.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
