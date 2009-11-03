# $NetBSD: Makefile,v 1.2 2009/11/03 17:22:06 thomasklausner Exp $
#

DISTNAME=		ganglia-3.1.2
PKGNAME=		ganglia-monitor-core-3.1.2
CATEGORIES=		net parallel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ganglia/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ganglia.sourceforge.net/
COMMENT=		Ganglia cluster monitor, monitoring daemon

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-gmetad
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++ fortran

SUBST_CLASSES+=		pkg_sysconfdir
SUBST_STAGE.pkg_sysconfdir=	pre-configure
SUBST_MESSAGE.pkg_sysconfdir=	Fixing PKG_SYSCONFDIR
SUBST_FILES.pkg_sysconfdir=	mans/gmetad.1 mans/gmetric.1 mans/gmond.1 \
			gmetad/cmdline.c gmetad/cmdline.h		\
			gmetric/cmdline.c gmetric/cmdline.h		\
			gmond/cmdline.c gmond/cmdline.h gmond/g25_config.h \
			ganglia.html
SUBST_VARS.pkg_sysconfdir=	PKG_SYSCONFDIR

EGDIR=			${PREFIX}/share/examples/ganglia
CONF_FILES=		${EGDIR}/gmond.conf ${PKG_SYSCONFDIR}/gmond.conf
CONF_FILES+=		${EGDIR}/gmetad.conf ${PKG_SYSCONFDIR}/gmetad.conf

RCD_SCRIPTS=		gmond gmetad

INSTALLATION_DIRS=	${EGDIR} ${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/mans/gmetad.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/mans/gmetric.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/mans/gmond.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/mans/gstat.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/gmetad/gmetad.conf ${DESTDIR}${EGDIR}/
	${WRKSRC}/gmond/gmond -t > ${DESTDIR}${EGDIR}/gmond.conf

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../devel/confuse/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
