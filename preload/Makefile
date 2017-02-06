# $NetBSD$

DISTNAME=	preload-0.6.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=preload/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://preload.sourceforge.net/
COMMENT=	Adaptive readahead daemon
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gawk
# The makefiles only seem to be compatible with BSD make
USE_TOOLS+=	gmake

RCD_SCRIPTS+=	preload

EGDIR=	${PREFIX}/share/examples/${PKGBASE}

CONF_FILES+=	${EGDIR}/logrotate.d/preload ${PKG_SYSCONFDIR}/logrotate.d/preload
CONF_FILES+=	${EGDIR}/preload.conf ${PKG_SYSCONFDIR}/preload.conf

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths+=		configure src/Makefile.in
SUBST_SED.fix-paths+=		-e '/initddir=/s,$${sysconfdir}/rc.d,${EGDIR},g'
SUBST_SED.fix-paths+=		-e '/sysconfigdir=/s,$${sysconfdir},${EGDIR},g'
SUBST_SED.fix-paths+=		-e '/logrotatedir=/s,$${sysconfdir},${EGDIR},g'
SUBST_SED.fix-paths+=		-e '/nodist_sysconfDATA_INSTALL/s,$$(sysconfdir),${EGDIR},g'
SUBST_SED.fix-paths+=		-e '/MKDIR_P/s,$$(sysconfdir),${EGDIR},g'

BUILDLINK_API_DEPENDS.glib2+=           glib2>=2.14.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
