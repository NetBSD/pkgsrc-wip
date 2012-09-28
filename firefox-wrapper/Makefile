# $NetBSD: Makefile,v 1.10 2012/09/28 22:26:46 asau Exp $

DISTNAME=	firefox-wrapper-0.3
CATEGORIES=	www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pancake@phreaker.net
COMMENT=	Firefox binary wrapper

NO_CONFIGURE=	yes
NO_BUILD=	yes

CONF_FILES=	${PREFIX}/share/examples/firefox-wrapper/firefox-wrapper.conf \
		${PKG_SYSCONFDIR}/firefox-wrapper.conf

INSTALLATION_DIRS=	bin

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/firefox ${DESTDIR}${PREFIX}/bin/firefox
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/firefox-wrapper/
	${INSTALL_DATA} ${WRKSRC}/firefox-wrapper.conf \
		${DESTDIR}${PREFIX}/share/examples/firefox-wrapper/firefox-wrapper.conf
	${INSTALL_DATA} ${WRKSRC}/firefox-wrapper.conf \
		${DESTDIR}${PKG_SYSCONFDIR}/firefox-wrapper.conf

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	post-patch
SUBST_FILES.etc=	firefox firefox-wrapper.conf
SUBST_SED.etc+=		-e "s,_etc_,${PKG_SYSCONFDIR},g" \
			-e "s,_pfx_,${PREFIX},g"

.include "../../mk/bsd.pkg.mk"
