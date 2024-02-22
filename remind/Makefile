# $NetBSD: Makefile,v 1.32 2022/06/28 11:36:59 wiz Exp $

DISTNAME=	remind-04.02.09
PKGNAME=	${DISTNAME:C/0([0-9])/\1/g}
PKGREVISION=	3
CATEGORIES=	time
MASTER_SITES=	https://dianne.skoll.ca/projects/remind/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dianne.skoll.ca/projects/remind/
COMMENT=	Calendar/alarm program with interpreted input language
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run autoconf

USE_FEATURES=	glob

TEST_TARGET=	test

INSTALLATION_DIRS=	share/examples/remind share/doc/remind

post-install:
	cd ${WRKSRC}; \
		${INSTALL_DATA} examples/defs.rem \
			${DESTDIR}${PREFIX}/share/examples/remind; \
		${INSTALL_DATA} examples/remind.vim \
			${DESTDIR}${PREFIX}/share/examples/remind; \
	cd ${WRKSRC}; \
		${INSTALL_DATA} docs/README.UNIX \
			${DESTDIR}${PREFIX}/share/doc/remind; \
		${INSTALL_DATA} docs/WHATSNEW \
			${DESTDIR}${PREFIX}/share/doc/remind; \
		${INSTALL_DATA} COPYRIGHT \
			${DESTDIR}${PREFIX}/share/doc/remind

.include "../../graphics/p5-cairo/buildlink3.mk"
.include "../../devel/p5-pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
