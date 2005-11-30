# $NetBSD: Makefile,v 1.9 2005/11/30 19:40:29 adrian_p Exp $

DISTNAME=	anope-1.7.12
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=anope/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.anope.org/
COMMENT=	Set of Services for IRC networks

GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require
USE_PKGINSTALL=		YES
USE_TOOLS+=		gmake perl:run

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=		anope
MAKE_ENV+=		RUNGROUP=${PKG_GROUPS}

CONF_FILES+=		${PREFIX}/share/examples/anope/example.conf \
			${PREFIX}/lib/anope/services.conf

CONFIGURE_ARGS+=	--with-permissions=077
CONFIGURE_ARGS+=	--with-bindir=${PREFIX}/lib/anope
CONFIGURE_ARGS+=	--with-datadir=${PREFIX}/lib/anope
CONFIGURE_ARGS+=	--with-rungroup=${PKG_GROUPS}

.include "options.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	data/example.chk data/example.conf
SUBST_SED.paths=	-e "s|/home/ircd/services|${PREFIX}/lib/anope|g" \
			-e "s|/usr/local/lib/services|${PREFIX}/lib/anope|g"
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."

SUBST_CLASSES+=		utils
SUBST_STAGE.utils=	post-patch
SUBST_FILES.utils=	src/Makefile
SUBST_SED.utils=	-e "s|find|${FIND}|g" \
			-e "s|chgrp|${CHGRP}|g" \
			-e "s|chmod|${CHMOD}|g" \
			-e "s|ln|${LN}|g"
SUBST_MESSAGE.utils=	"Fixing hardcoded utilities."

.include "../../mk/pthread.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/anope
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/anope
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/anope
	@${CHMOD} ${BINMODE} ${PREFIX}/lib/anope/anoperc
	@${CHMOD} ${BINMODE} ${PREFIX}/lib/anope/listchans
	@${CHMOD} ${BINMODE} ${PREFIX}/lib/anope/listnicks
	@${CHMOD} ${BINMODE} ${PREFIX}/lib/anope/services
	@${CHMOD} ${BINMODE} ${PREFIX}/lib/anope/modules/*.so
	${INSTALL_DATA} ${WRKSRC}/data/* ${PREFIX}/share/examples/anope

.include "../../mk/bsd.pkg.mk"
