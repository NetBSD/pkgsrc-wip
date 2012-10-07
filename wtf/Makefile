# $NetBSD: Makefile,v 1.2 2012/10/07 20:11:08 asau Exp $
#

DISTNAME=	wtf-20080926
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITES_FREEBSD_LOCAL:=jadawin/}

MAINTAINER=	pho@cielonegro.org
COMMENT=	Translate common Internet acronyms
LICENSE=	public-domain

NO_BUILD=				yes

SUBST_CLASSES+=				fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		wtf
SUBST_FILES.fix-paths+=		wtf.6
SUBST_SED.fix-paths=		-e 's,/usr/share/misc/,${PREFIX}/share/wtf/,g'

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS+= bin
INSTALLATION_DIRS+=	share/wtf
INSTALLATION_DIRS+=	${PKGMANDIR}/man6

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wtf           ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA}   ${WRKSRC}/acronyms      ${DESTDIR}${PREFIX}/share/wtf/
	${INSTALL_DATA}   ${WRKSRC}/acronyms.comp ${DESTDIR}${PREFIX}/share/wtf/
	${INSTALL_MAN}    ${WRKSRC}/wtf.6         ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/

.include "../../mk/bsd.pkg.mk"
