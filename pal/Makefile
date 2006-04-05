# $NetBSD: Makefile,v 1.1.1.1 2006/04/05 08:10:26 emil_s Exp $
#

DISTNAME=		pal-0.3.4
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=palcal/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://palcal.sourceforge.net/
COMMENT=		Command-line calendar program

WRKSRC=			${WRKDIR}/${DISTNAME}/src

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
USE_GNU_READLINE=	yes
MANCOMPRESSED=		yes

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing hardcoded paths
SUBST_FILES.path=	Makefile.defs Makefile input.c ../pal.conf
SUBST_SED.path=		-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.path+=	-e 's,@PKGMANDIR@,${PKGMANDIR},g'
SUBST_SED.path+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.path+=	-e 's,@EGDIR@,${EGDIR},g'

EGDIR=			${PREFIX}/share/examples/pal

CONF_FILES=		${EGDIR:Q}/pal.conf ${PKG_SYSCONFDIR:Q}/pal.conf


do-build:
	cd ${WRKSRC:Q} && make

do-install:
	cd ${WRKSRC:Q} && make install-no-rm


.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
