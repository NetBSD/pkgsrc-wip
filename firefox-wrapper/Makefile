# $NetBSD: Makefile,v 1.9 2009/04/09 01:19:15 jsonn Exp $

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

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/firefox ${PREFIX}/bin/firefox
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/firefox-wrapper/
	${INSTALL_DATA} ${WRKSRC}/firefox-wrapper.conf \
		${PREFIX}/share/examples/firefox-wrapper/firefox-wrapper.conf
	${INSTALL_DATA} ${WRKSRC}/firefox-wrapper.conf \
		${PKG_SYSCONFDIR}/firefox-wrapper.conf

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	post-patch
SUBST_FILES.etc=	firefox firefox-wrapper.conf
SUBST_SED.etc+=		-e "s,_etc_,${PKG_SYSCONFDIR},g" \
			-e "s,_pfx_,${PREFIX},g"

.include "../../mk/bsd.pkg.mk"
