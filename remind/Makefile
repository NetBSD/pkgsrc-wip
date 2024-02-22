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
USE_TOOLS+=	perl:run

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

		${INSTALL_SCRIPT} ${WRKSRC}/rem2pdf/bin/rem2pdf \
			${DESTDIR}${PREFIX}/bin/rem2pdf

		${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
		${INSTALL_MAN} ${WRKSRC}/rem2pdf/blib/man1/rem2pdf.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

		${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
		${INSTALL_MAN} ${WRKSRC}/rem2pdf/blib/man3/Remind\::* \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3

		# TODO: interpreter of script ("#!perl") must be changed...
		#${INSTALL_SCRIPT} ${WRKSRC}/rem2html/rem2html \
		#${DESTDIR}${PREFIX}/bin/rem2html

.include "../../graphics/p5-cairo/buildlink3.mk"
.include "../../devel/p5-pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
