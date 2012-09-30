# $NetBSD: Makefile,v 1.12 2012/09/30 05:19:44 asau Exp $
#
DISTNAME=	igal-1.4.7-wt
CATEGORIES=	www graphics
MASTER_SITES=	http://trexler.at/igal/

MAINTAINER=	drue@users.sf.net
HOMEPAGE=	http://trexler.at/igal/
COMMENT=	Online image gallery generator

DEPENDS+=	ImageMagick>=5.0:../../graphics/ImageMagick

NO_CONFIGURE=		YES
NO_BUILD=		YES
REPLACE_PERL=		igal
USE_TOOLS+=		perl:run
USE_PKGLOCALEDIR=	YES

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		post-patch
SUBST_MESSAGE.fix-prefix=	Fixing relative prefix
SUBST_FILES.fix-prefix=		igal
SUBST_SED.fix-prefix=		-e 's,/usr/local/lib/igal,${PREFIX}/share/igal,'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/igal ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/igal.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/igal
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/igal
	cd ${WRKSRC} && \
	${INSTALL_DATA} indextemplate.html slidetemplate.html tile.png igal.css ${DESTDIR}${PREFIX}/share/igal
	cd ${WRKSRC} && \
	${INSTALL_DATA} README THANKS ChangeLog COPYING ${DESTDIR}${PREFIX}/share/doc/igal

.include "../../mk/bsd.pkg.mk"
