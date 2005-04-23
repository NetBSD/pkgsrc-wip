# $NetBSD: Makefile,v 1.5 2005/04/23 16:51:43 poppnk Exp $

DISTNAME=	firefox-wrapper-0.1
CATEGORIES=	www wip
MASTER_SITES=	# empty
DISTFILES=	# empty
PKGREVISION=	1

MAINTAINER=	pancake@phreaker.net
COMMENT=	Firefox binary wrapper

NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
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
SUBST_SED.etc+=	-e "s,_etc_,${PKG_SYSCONFDIR},g" \
			-e "s,_pfx_,${PREFIX},g"

.include "../../mk/bsd.pkg.mk"
