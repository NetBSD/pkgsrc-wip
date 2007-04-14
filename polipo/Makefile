# $NetBSD: Makefile,v 1.2 2007/04/14 01:53:36 ishit Exp $
#

DISTNAME=		polipo-1.0.0
CATEGORIES=		www wip
MASTER_SITES=		http://www.pps.jussieu.fr/~jch/software/files/polipo/
MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.pps.jussieu.fr/~jch/software/polipo/
COMMENT=		Small and fast caching web proxy

USE_TOOLS+=	makeinfo install-info

BUILD_DEFS+=	VARBASE

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		Makefile *.sample polipo.man polipo.texi *.c
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=		-e 's,/var/cache,${VARBASE}/cache,g'
SUBST_SED.fix-paths+=		-e 's,/etc/polipo,${PKG_SYSCONFDIR}/polipo,g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/polipo/www etc/polipo

post-build:
	${CP} ${WRKSRC}/polipo.man ${WRKSRC}/polipo.1

do-install:
	${INSTALL_DATA_DIR} ${VARBASE}/cache/polipo
	${INSTALL_PROGRAM} ${WRKSRC}/polipo ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/polipo.1 ${PREFIX}/${PKGMANDIR}/man1
	install-info --info-dir=${PREFIX}/${PKGINFODIR} ${WRKSRC}/polipo.info
	${INSTALL_DATA} ${WRKSRC}/*.sample ${PREFIX}/share/polipo
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/polipo
	${INSTALL_DATA} ${WRKSRC}/html/* ${PREFIX}/share/polipo/www

.include "../../mk/bsd.pkg.mk"
