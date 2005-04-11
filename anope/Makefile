# $NetBSD: Makefile,v 1.3 2005/04/11 21:09:42 tvierling Exp $

DISTNAME=	anope-1.7.8
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=anope/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.anope.org/
COMMENT=	Set of Services for IRC networks

GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require
USE_PKGINSTALL=		YES
USE_GNU_TOOLS+=		make
USE_PERL5=		build

.include "../../mk/bsd.prefs.mk"

ANOPE_GROUP?=		anope
PKG_GROUPS=		${ANOPE_GROUP}
BUILD_DEFS+=		ANOPE_GROUP
MAKE_ENV+=		RUNGROUP=${ANOPE_GROUP}

CONF_FILES+=		${PREFIX}/share/examples/anope/example.conf \
			${PREFIX}/share/anope/services.conf

CONFIGURE_ARGS+=	--without-encryption
CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--with-permissions=077
CONFIGURE_ARGS+=	--with-bindir=${PREFIX}/share/anope
CONFIGURE_ARGS+=	--with-datadir=${PREFIX}/share/anope
CONFIGURE_ARGS+=	--with-rungroup=${ANOPE_GROUP}

.include "options.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	data/example.chk data/example.conf
SUBST_SED.paths=	-e "s|/home/ircd/services|${PREFIX}/share/anope|g" \
			-e "s|/usr/local/lib/services|${PREFIX}/share/anope|g"
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/anope
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/anope
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/anope
	@${CHMOD} ${BINMODE} ${PREFIX}/share/anope/anoperc
	@${CHMOD} ${BINMODE} ${PREFIX}/share/anope/listchans
	@${CHMOD} ${BINMODE} ${PREFIX}/share/anope/listnicks
	@${CHMOD} ${BINMODE} ${PREFIX}/share/anope/services
	@${CHMOD} ${BINMODE} ${PREFIX}/share/anope/modules/*.so
	${INSTALL_DATA} ${WRKSRC}/data/* ${PREFIX}/share/examples/anope

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
