# $NetBSD: Makefile,v 1.7 2012/10/07 17:17:36 asau Exp $
#

DISTNAME=	tinyca2-0.7.5
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://tinyca.sm-zone.net/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://tinyca.sm-zone.net/
COMMENT=	GUI written in Perl/Gtk to manage a small CA

DEPENDS+=	p5-gtk2>=1.072:../../x11/p5-gtk2
DEPENDS+=	p5-gettext-[0-9]*:../../devel/p5-gettext
DEPENDS+=	zip-[0-9]*:../../archivers/zip


NO_BUILD=	YES
CADIR=		${PREFIX}/share/tinyca2

USE_TOOLS+=	perl:run
REPLACE_PERL+=	tinyca2

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7e


SUBST_CLASSES+=		script
SUBST_STAGE.script=	post-patch
SUBST_FILES.script=	tinyca2
SUBST_SED.script=	-e "s|./lib|${CADIR}|g"
SUBST_SED.script+=	-e "s|/usr/bin/openssl|${BUILDLINK_PREFIX.openssl}/bin/openssl|g"
SUBST_SED.script+=	-e "s|/usr/bin/zip|${PREFIX}/bin/zip|g"
SUBST_SED.script+=	-e "s|./templates|${CADIR}/templates|g"
SUBST_MESSAGE.script=	Fixing hardcoded paths.

INSTALLATION_DIRS=	bin

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${CADIR}
	${INSTALL_DATA_DIR} ${CADIR}/GUI
	${INSTALL_DATA_DIR} ${CADIR}/templates
	${INSTALL_SCRIPT} ${WRKSRC}/tinyca2 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.pm ${CADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/GUI/*.pm ${CADIR}/GUI
	${INSTALL_DATA} ${WRKSRC}/templates/openssl.cnf ${CADIR}/templates

.include "../../mk/bsd.pkg.mk"
