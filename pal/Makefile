# $NetBSD: Makefile,v 1.6 2012/10/04 19:44:06 asau Exp $
#

DISTNAME=		pal-0.4.3
#PKGREVISION=		1
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=palcal/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		esg@sdf.lonestar.org
HOMEPAGE=		http://palcal.sourceforge.net/
COMMENT=		Command-line calendar program

WRKSRC=			${WRKDIR}/${DISTNAME}/src


USE_TOOLS+=		gmake pkg-config
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

CONF_FILES=		${EGDIR}/pal.conf ${PKG_SYSCONFDIR}/pal.conf

MAKE_JOBS_SAFE=		no

USE_NCURSES=		yes

CFLAGS+=		-DCURSES

do-build:
	cd ${WRKSRC} && make

do-install:
	cd ${WRKSRC} && make install-no-rm


.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
